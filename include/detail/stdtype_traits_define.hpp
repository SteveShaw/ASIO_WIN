#ifndef ASIO_WIN_DETAIL_STDTYPE_TRAITS_DEFINE_HPP
#define ASIO_WIN_DETAIL_STDTYPE_TRAITS_DEFINE_HPP

#include <config.hpp>
#include <type_traits>
#include <utility>

namespace asio_win
{
using std::add_const;
using std::conditional;
using std::decay;
using std::enable_if;
using std::false_type;
using std::integral_constant;
using std::is_base_of;
using std::is_class;
using std::is_const;
using std::is_convertible;
using std::is_function;
using std::is_same;
using std::remove_pointer;
using std::remove_reference;
using std::result_of;
using std::true_type;

}

#endif // ASIO_WIN_DETAIL_STDTYPE_TRAITS_DEFINE_HPP
