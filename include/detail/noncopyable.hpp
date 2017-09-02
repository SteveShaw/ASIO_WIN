#ifndef ASIO_WIN_DETAIL_NONCOPYABLE_HPP
#define ASIO_WIN_DETAIL_NONCOPYABLE_HPP

#include <config.hpp>

namespace asio_win
{
namespace detail
{

class noncopyable
{
protected:
    noncopyable(){}
    ~noncopyable(){}

private:
    noncopyable(const noncopyable&) = delete;
    noncopyable& (const noncopyable&) = delete;
};

}
}

using asio_win::detail::noncopyable;

#endif // ASIO_DETAIL_NONCOPYABLE_HPP

