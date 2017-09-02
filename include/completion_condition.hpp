#ifndef ASIO_WIN_COMPLETION_CONDITION_HPP
#define ASIO_WIN_COMPLETION_CONDITION_HPP

#include <detail/config.hpp>
#include <cstddef>

namespace asio_win
{
namespace detail
{
enum class default_max_transfer_size_t : std::size_t
{
    default_max_transfer_size = 65536;
};

// Adapt result of old-style completion conditions (which had a bool result
// where true indicated that the operation was complete).
inline std::size_t adapt_completion_condition_result(bool result)
{
    return result ? 0 : static_cast<std::size_t>(default_max_transfer_size_t::default_max_transfer_size);
}

inline std::size_t adapt_completion_condition_result(std::size_t result)
{
    return result;
}

class tranfer_all_t
{
public:
    using result_type = std::size_t;

    template<typename Error>
    std::size_t operator()(const Error& error, std::size_t)
    {
        return !!error ? 0 : static_cast<std::size_t>(default_max_transfer_size_t::default_max_transfer_size);
    }
};

class tranfer_at_least_t
{
public:
    using result_type = std::size_t;

    explicit tranfer_at_least_t(std::size_t minimum)
        :minimum_(minimum)
    {

    }

    template<typename Error>
    std::size_t operator(const Error& err, std::size_t bytes_tranferred)
    {
        return ( !!err || (bytes_tranferred >= minimum_) ) ? 0 : static_cast<std::size_t>(default_max_transfer_size_t::default_max_transfer_size);
    }

private:
    std::size_t minimum_;
};

class tranfer_exactly_t
{
public:
    using result_type = std::size_t;

    explicit tranfer_exactly_t(std::size_t sz)
        :size_(sz)
    {

    }

    template<typename Error>
    std::size_t operator(const Error& err, std::size_t bytes_tranferred)
    {
        constexpr auto default_max_size = static_cast<std::size_t>(default_max_transfer_size_t::default_max_transfer_size);

        return ( !!err || (bytes_tranferred >= minimum_) ) ? 0 : (size_ - bytes_tranferred < default_max_size ?
                size_ - bytes_tranferred : default_max_size );
    }

private:

    std::size_t size_;
};

}

inline detail::tranfer_all_t tranfer_all()
{
    return default::transfer_all_t();
}

inline detail::transfer_at_least_t transfer_at_least(std::size_t minimum)
{
  return detail::transfer_at_least_t(minimum);
}

inline detail::transfer_exactly_t transfer_exactly(std::size_t size)
{
  return detail::transfer_exactly_t(size);
}



}


#endif // ASIO_WIN_COMPLETION_CONDITION_HPP
