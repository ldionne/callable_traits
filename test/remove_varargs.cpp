/*
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <boost/callable_traits/remove_varargs.hpp>
#include "test.hpp"



struct foo {};

int main() {

    {
        using f      = void(foo::*)();
        using l      = void(foo::*)() LREF;
        using r      = void(foo::*)() RREF ;
        using c      = void(foo::*)() const;
        using cl     = void(foo::*)() const LREF;
        using cr     = void(foo::*)() const RREF;
        using v      = void(foo::*)() volatile;
        using vl     = void(foo::*)() volatile LREF;
        using vr     = void(foo::*)() volatile RREF;
        using cv     = void(foo::*)() const volatile;
        using cvl    = void(foo::*)() const volatile LREF;
        using cvr    = void(foo::*)() const volatile RREF;

        using va_f   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...);
        using va_l   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) LREF;
        using va_r   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) RREF ;
        using va_c   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const;
        using va_cl  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const LREF;
        using va_cr  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const RREF;
        using va_v   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) volatile;
        using va_vl  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) volatile LREF;
        using va_vr  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) volatile RREF;
        using va_cv  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const volatile;
        using va_cvl = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const volatile LREF;
        using va_cvr = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(...) const volatile RREF;

        CT_ASSERT(std::is_same<f,    remove_varargs_t<va_f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<va_l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<va_r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<va_c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<va_cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<va_cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<va_v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<va_vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<va_vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<va_cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<va_cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<va_cvr>>{});

        CT_ASSERT(std::is_same<f,    remove_varargs_t<f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<cvr>>{});
    }

    {
        using f      = void(foo::*)(int&, int&&);
        using l      = void(foo::*)(int&, int&&) LREF;
        using r      = void(foo::*)(int&, int&&) RREF ;
        using c      = void(foo::*)(int&, int&&) const;
        using cl     = void(foo::*)(int&, int&&) const LREF;
        using cr     = void(foo::*)(int&, int&&) const RREF;
        using v      = void(foo::*)(int&, int&&) volatile;
        using vl     = void(foo::*)(int&, int&&) volatile LREF;
        using vr     = void(foo::*)(int&, int&&) volatile RREF;
        using cv     = void(foo::*)(int&, int&&) const volatile;
        using cvl    = void(foo::*)(int&, int&&) const volatile LREF;
        using cvr    = void(foo::*)(int&, int&&) const volatile RREF;

        using va_f   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...);
        using va_l   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) LREF;
        using va_r   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) RREF ;
        using va_c   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const;
        using va_cl  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const LREF;
        using va_cr  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const RREF;
        using va_v   = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) volatile;
        using va_vl  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) volatile LREF;
        using va_vr  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) volatile RREF;
        using va_cv  = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const volatile;
        using va_cvl = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const volatile LREF;
        using va_cvr = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const volatile RREF;

        CT_ASSERT(std::is_same<f,    remove_varargs_t<va_f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<va_l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<va_r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<va_c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<va_cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<va_cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<va_v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<va_vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<va_vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<va_cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<va_cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<va_cvr>>{});

        CT_ASSERT(std::is_same<f,    remove_varargs_t<f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<cvr>>{});
    }

#ifndef BOOST_CLBL_TRTS_DISABLE_ABOMINABLE_FUNCTIONS

    {
        using f      = void();
        using l      = void() LREF;
        using r      = void() RREF ;
        using c      = void() const;
        using cl     = void() const LREF;
        using cr     = void() const RREF;
        using v      = void() volatile;
        using vl     = void() volatile LREF;
        using vr     = void() volatile RREF;
        using cv     = void() const volatile;
        using cvl    = void() const volatile LREF;
        using cvr    = void() const volatile RREF;

        using va_f   = void(...);
        using va_l   = void(...) LREF;
        using va_r   = void(...) RREF ;
        using va_c   = void(...) const;
        using va_cl  = void(...) const LREF;
        using va_cr  = void(...) const RREF;
        using va_v   = void(...) volatile;
        using va_vl  = void(...) volatile LREF;
        using va_vr  = void(...) volatile RREF;
        using va_cv  = void(...) const volatile;
        using va_cvl = void(...) const volatile LREF;
        using va_cvr = void(...) const volatile RREF;

        CT_ASSERT(std::is_same<f,    remove_varargs_t<va_f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<va_l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<va_r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<va_c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<va_cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<va_cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<va_v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<va_vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<va_vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<va_cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<va_cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<va_cvr>>{});

        CT_ASSERT(std::is_same<f,    remove_varargs_t<f>>{});
        CT_ASSERT(std::is_same<l,    remove_varargs_t<l>>{});
        CT_ASSERT(std::is_same<r,    remove_varargs_t<r>>{});
        CT_ASSERT(std::is_same<c,    remove_varargs_t<c>>{});
        CT_ASSERT(std::is_same<cl,   remove_varargs_t<cl>>{});
        CT_ASSERT(std::is_same<cr,   remove_varargs_t<cr>>{});
        CT_ASSERT(std::is_same<v,    remove_varargs_t<v>>{});
        CT_ASSERT(std::is_same<vl,   remove_varargs_t<vl>>{});
        CT_ASSERT(std::is_same<vr,   remove_varargs_t<vr>>{});
        CT_ASSERT(std::is_same<cv,   remove_varargs_t<cv>>{});
        CT_ASSERT(std::is_same<cvl,  remove_varargs_t<cvl>>{});
        CT_ASSERT(std::is_same<cvr,  remove_varargs_t<cvr>>{});
    }

#endif //#ifndef BOOST_CLBL_TRTS_DISABLE_ABOMINABLE_FUNCTIONS

    {
        using f = void(&)();
        using va_f = void(&)(...);
        CT_ASSERT(std::is_same<f,    remove_varargs_t<va_f>>{});
    }
}
