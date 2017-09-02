#ifndef ASIO_WIN_DETAIL_ATOMIC_COUNTER_HPP
#define ASIO_WIN_DETAIL_ATOMIC_COUNTER_HPP

#include <config.hpp>
#include <atomic>

namespace asio_win
{
namespace detail
{
using atomic_counter = std::atomic<long>;
inline void increment(atomic_counter& a, long b)
{
    a += b;
}
}
}

#endif // ASIO_WIN_DETAIL_ATOMIC_COUNTER_HPP
