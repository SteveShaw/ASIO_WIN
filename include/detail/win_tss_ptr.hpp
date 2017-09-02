#ifndef ASIO_WIN_DETAIL_WIN_TSS_PTR_HPP
#define ASIO_WIN_DETAIL_WIN_TSS_PTR_HPP

#include <config.hpp>
#include <noncopyable.hpp>

namespace asio_win
{
    namespace detail
    {
        template<typename T>
        class win_tss_ptr : private noncopyable
        {
        public:

        };
    }
}

#endif // ASIO_WIN_DETAIL_WIN_TSS_PTR_HPP
