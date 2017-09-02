#ifndef ASIO_WIN_FWD_HANDLER_ALLOCATOR_HOOK_HPP
#define ASIO_WIN_FWD_HANDLER_ALLOCATOR_HOOK_HPP

#include <../detail/config.hpp>
#include <cstddef>

namespace asio_win
{
    void *asio_win_handler_allocate(std::size_t size, ...);
    void asio_win_handler_deallocate(void *pointer, std::size_t size, ...);
}


#endif // ASIO_WIN_FWD_HANDLER_ALLOCATOR_HOOK_HPP
