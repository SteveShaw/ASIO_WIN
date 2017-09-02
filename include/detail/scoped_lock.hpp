#ifndef ASIO_WIN_DETAIL_SCOPED_LOCK_HPP
#define ASIO_WIN_DETAIL_SCOPED_LOCK_HPP

#include <config.hpp>

namespace asio_win
{
namespace detail
{
template<typename Mutex>
class scoped_lock : private noncopyable
{
private:
    enum class adopt_lock_t {adopt_lock};

    scoped_lock(Mutex& m, adopt_lock_t)
    :mutex_(m), locked_(true)
    {

    }

    explicit scoped_lock(Mutex& m)
    :mutex_(m)
    {
        mutex_.lock();
        locked_ = true;
    }

    ~scoped_lock()
    {
        if(locked_)
        {
            mutex_.unlock();
        }
    }

    void lock()
    {
        if(!locked_)
        {
            mutex_.lock();
            locked_ = true;
        }
    }

    void unlock()
    {
        if(locked)
        {
            mutex_.unlock();
            locked_ = false;
        }
    }

    Mutex& mutex()
    {
        return mutex_;
    }

private:
    Mutex& mutex_;

    bool locked_;
};
}
}

#endif // ASIO_WIN_DETAIL_SCOPED_LOCK_HPP
