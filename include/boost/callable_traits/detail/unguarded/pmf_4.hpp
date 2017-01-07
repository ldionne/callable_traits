/*
Copyright (c) 2016 Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

HEADER GUARDS INTENTIONALLY OMITTED
DO NOT INCLUDE THIS HEADER DIRECTLY

CALLABLE_TRAITS_INCLUDE_QUALIFIERS - the function-level qualifiers for the
    current inclusion (combinations of `const` `volatile` `&` `&&`, or nothing)

CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE - the transaction_safe specifier for
    the current include (`transaction_safe` or nothing)

CALLABLE_TRAITS_IS_TRANSACTION_SAFE - `std::true_type` or `std::false_type`,
    tied on whether CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE is `transaction_safe`

CALLABLE_TRAITS_TRANSACTION_SAFE_SPECIFIER - `transaction_safe` when
    CALLABLE_TRAITS_ENABLE_TRANSACTION_SAFE is defined, otherwise nothing

CALLABLE_TRAITS_INCLUDE_NOEXCEPT - the noexcept specifier for
    the current include (`noexcept` or nothing)

CALLABLE_TRAITS_IS_NOEXCEPT - `std::true_type` or `std::false_type`,
    tied on whether CALLABLE_TRAITS_INCLUDE_NOEXCEPT is `noexcept`

CALLABLE_TRAITS_NOEXCEPT_SPECIFIER - `noexcept` if
    CALLABLE_TRAITS_ENABLE_NOEXCEPT_TYPES is defined, otherwise nothing
*/

template<typename Return, typename T, typename... Args>
struct pmf<Return(CALLABLE_TRAITS_CC T::*)(Args...)
    CALLABLE_TRAITS_INCLUDE_QUALIFIERS
    CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
    CALLABLE_TRAITS_INCLUDE_NOEXCEPT>
    : default_callable_traits<dummy CALLABLE_TRAITS_INCLUDE_QUALIFIERS> {
     
    static constexpr bool value = true;
    
    using traits = pmf;

    using return_type = Return;

    using type = Return(CALLABLE_TRAITS_CC T::*)(Args...)
        CALLABLE_TRAITS_INCLUDE_QUALIFIERS
        CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
        CALLABLE_TRAITS_INCLUDE_NOEXCEPT;

    using invoke_type = typename std::conditional<
        std::is_rvalue_reference<T CALLABLE_TRAITS_INCLUDE_QUALIFIERS>::value,
        T CALLABLE_TRAITS_INCLUDE_QUALIFIERS,
        typename std::add_lvalue_reference<T CALLABLE_TRAITS_INCLUDE_QUALIFIERS>::type
    >::type;
    
    using arg_types = std::tuple<invoke_type, Args...>;
    using non_invoke_arg_types = std::tuple<Args...>;

    using function_object_signature = Return(Args...);

    using function_type = Return(invoke_type, Args...);

    using qualified_function_type = Return(Args...)
        CALLABLE_TRAITS_INCLUDE_ABOMINABLE_QUALIFIERS
        CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
        CALLABLE_TRAITS_INCLUDE_NOEXCEPT;

    using remove_varargs = type;
    
    using add_varargs =
        Return(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...)
            CALLABLE_TRAITS_INCLUDE_QUALIFIERS
            CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
            CALLABLE_TRAITS_INCLUDE_NOEXCEPT;
    
    using is_noexcept = CALLABLE_TRAITS_IS_NOEXCEPT;

    using remove_noexcept = Return(CALLABLE_TRAITS_CC T::*)(Args...)
        CALLABLE_TRAITS_INCLUDE_QUALIFIERS
        CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE;

    using add_noexcept = Return(CALLABLE_TRAITS_CC T::*)(Args...)
        CALLABLE_TRAITS_INCLUDE_QUALIFIERS
        CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
        CALLABLE_TRAITS_NOEXCEPT_SPECIFIER;

    using is_transaction_safe = CALLABLE_TRAITS_IS_TRANSACTION_SAFE;

    using remove_transaction_safe = Return(CALLABLE_TRAITS_CC T::*)(Args...)
        CALLABLE_TRAITS_INCLUDE_QUALIFIERS
        CALLABLE_TRAITS_INCLUDE_NOEXCEPT;

    using add_transaction_safe = Return(CALLABLE_TRAITS_CC T::*)(Args...)
        CALLABLE_TRAITS_INCLUDE_QUALIFIERS
        CALLABLE_TRAITS_TRANSACTION_SAFE_SPECIFIER
        CALLABLE_TRAITS_INCLUDE_NOEXCEPT;

    using class_type = T;

    using qualifiers = default_callable_traits<dummy CALLABLE_TRAITS_INCLUDE_QUALIFIERS>;
    
    template<qualifier_flags Flags>
    using set_qualifiers = set_member_function_qualifiers<
            Flags, is_transaction_safe::value, is_noexcept::value,
            CALLABLE_TRAITS_CC_TAG, T, Return, Args...>;
        
    using remove_member_reference = set_qualifiers<qualifiers::cv_flags>;
    
    using add_member_lvalue_reference = set_qualifiers<
        collapse_flags<qualifiers::q_flags, lref_>::value>;
        
    using add_member_rvalue_reference = set_qualifiers<
        collapse_flags<qualifiers::q_flags, rref_>::value>;
        
    using add_member_const = set_qualifiers<qualifiers::q_flags | const_>;

    using add_member_volatile = set_qualifiers<qualifiers::q_flags | volatile_>;

    using add_member_cv = set_qualifiers<qualifiers::q_flags | cv_>;
    
    using remove_member_const = set_qualifiers<
        qualifiers::ref_flags | remove_const_flag<qualifiers::cv_flags>::value>;
        
    using remove_member_volatile = set_qualifiers<
        qualifiers::ref_flags | remove_volatile_flag<qualifiers::cv_flags>::value>;
        
    using remove_member_cv = set_qualifiers<qualifiers::ref_flags>;
    
    template<typename U>
    using apply_member_pointer =
        Return(CALLABLE_TRAITS_CC U::*)(Args...)
            CALLABLE_TRAITS_INCLUDE_QUALIFIERS
            CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
            CALLABLE_TRAITS_INCLUDE_NOEXCEPT;
        
    template<typename NewReturn>
    using apply_return =
        NewReturn(CALLABLE_TRAITS_CC T::*)(Args...)
            CALLABLE_TRAITS_INCLUDE_QUALIFIERS
            CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
            CALLABLE_TRAITS_INCLUDE_NOEXCEPT;
        
    template<template<class...> class Container>
    using expand_args = Container<invoke_type, Args...>;

    template<template<class...> class Container, typename... RightArgs>
    using expand_args_left = Container<invoke_type, Args..., RightArgs...>;

    template<template<class...> class Container, typename... LeftArgs>
    using expand_args_right = Container<LeftArgs..., invoke_type, Args...>;

    using clear_args =
        Return(CALLABLE_TRAITS_CC T::*)()
            CALLABLE_TRAITS_INCLUDE_QUALIFIERS
            CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE
            CALLABLE_TRAITS_INCLUDE_NOEXCEPT;

#undef CALLABLE_TRAITS_BEGIN_PACK_MANIP
#undef CALLABLE_TRAITS_ARGS_PACK
#undef CALLABLE_TRAITS_END_PACK_MANIP

#define CALLABLE_TRAITS_BEGIN_PACK_MANIP Return( CALLABLE_TRAITS_CC T::*)(
#define CALLABLE_TRAITS_ARGS_PACK Args
#define CALLABLE_TRAITS_END_PACK_MANIP \
    ) CALLABLE_TRAITS_INCLUDE_QUALIFIERS \
    CALLABLE_TRAITS_INCLUDE_TRANSACTION_SAFE \
    CALLABLE_TRAITS_INCLUDE_NOEXCEPT

#include <boost/callable_traits/detail/unguarded/args_pack_manipulations.hpp>
#undef CALLABLE_TRAITS_BEGIN_PACK_MANIP
#undef CALLABLE_TRAITS_ARGS_PACK
#undef CALLABLE_TRAITS_END_PACK_MANIP

};
