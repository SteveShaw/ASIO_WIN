#ifndef ASIO_WIN_DETAIL_EVENT_HPP
#define ASIO_WIN_DETAIL_EVENT_HPP

#include <config.hpp>

namespace asio_win
{
namespace detail
{
class win_event
{
public:
    win_event();

    ~win_event();

    // Signal the event. (Retained for backward compatibility.)
    template<typename Lock>
    void signal(Lock& lock)
    {
        this->signal_all(lock);
    }

    // Signal all waiters.
    template<typename Lock>
    void signal_all(Lock& lock)
    {
        (void)lock;
        state_ |= 1;
        ::SetEvent(events_[0]);
    }

private:

    HANDLE events_[2];
    std::size_t state_;
};

}
}

#endif // ASIO_WIN_DETAIL_EVENT_HPP
