#ifndef ASIO_WIN_ASSOCIATE_ALLOCATORS_HPP
#define ASIO_WIN_ASSOCIATE_ALLOCATORS_HPP

#include <detail/config.hpp>
#include <detail/stdtype_traits_define.hpp>

namespace asio_win
{
namespace detail
{

template<typename T, typename E, typename=void>
struct associate_allocator_impl
{
    using type = E;

    static type get(const T&, const E& e) noexcept(true)
    {
        return e;
    }
};

template<typename T, typename E>
struct associate_allocator_impl<T, E, decltype((void)(*(typename T::allocator_type*)0))>
{
    using type = typename T::allocator_type;

    static type get(const T&t, const E&) noexcept(true)
    {
        return t.get_allocator();
    }
};

}

template<typename T, typename Allocator=std::allocator<void>>
struct associated_allocator
{
    using allocator_type = typename detail::associate_allocator_impl<T, Allocator>::type;

    static allocator_type  get(const T& t, const Allocator& a = Allocator()) noexcept(true)
    {
        return detail::associate_allocator_impl<T, Allocator>::get(t, a);
    }
};

//helper function to get associated_allocator

template<typename T>
inline auto get_associated_allocator(const T& t) noexcept(true)
{
    return associated_allocator::get(t);
}

template<typename T, typename Allocator>
inline auto get_associated_allocator(const T& t, const Allocator& a) noexcept(true)
{
    return associated_allocator::get(t, a);
}

template<typename T, typename Allocator = std::allocator<void>>
using associated_allocator_t = typename associated_allocator::allocator_type;

}

#endif // ASIO_WIN_ASSOCIATE_ALLOCATORS_HPP
