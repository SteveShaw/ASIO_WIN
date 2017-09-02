#ifndef ASIO_WIN_DETAIL_STDMEMORY_DEFINE_HPP
#define ASIO_WIN_DETAIL_STDMEMORY_DEFINE_HPP

#include <config.hpp>
#include <memory>

namespace asio_win
{

namespace detail
{
using std::shared_ptr;
using std::weak_ptr;
using std::addressof;
}

using std::allocator_arg_t;

#define ASIO_WIN_USE_ALLOCATOR(t)       \
namespace std {                         \
    template<typename Allocator>        \
    struct use_allocator<t, Allocator>  \
    : true_type                         \
    {};                                 \
}                                       \


#define ASIO_WIN_REBIND_ALLOC(alloc, t)                             \
typename std::allocator_traits<alloc>::template rebind_alloc<t>     \

}

#endif // ASIO_WIN_DETAIL_STDMEMORY_DEFINE_HPP
