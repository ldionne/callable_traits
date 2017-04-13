/*
@copyright Barrett Adair 2016

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_CONFIG_HPP
#define CALLABLE_TRAITS_CONFIG_HPP

#include <type_traits>

#define CALLABLE_TRAITS_NAMESPACE_BEGIN namespace boost { namespace callable_traits {
#define CALLABLE_TRAITS_NAMESPACE_END }}

#define CALLABLE_TRAITS_DETAIL_NAMESPACE_BEGIN namespace boost { namespace callable_traits { namespace detail {
#define CALLABLE_TRAITS_DETAIL_NAMESPACE_END }}}

#define CALLABLE_TRAITS_EMPTY_
#define CALLABLE_TRAITS_EMPTY CALLABLE_TRAITS_EMPTY_

#ifdef __cpp_transactional_memory
# define CALLABLE_TRAITS_ENABLE_TRANSACTION_SAFE
#endif

#ifdef __cpp_noexcept_function_type
# define CALLABLE_TRAITS_ENABLE_NOEXCEPT_TYPES
#endif

#ifdef __cpp_noexcept_function_type
#define CALLABLE_TRAITS_ENABLE_NOEXCEPT_TYPES
#endif

#ifndef __clang__
#  if defined(__GNUC__)
#    define CALLABLE_TRAITS_GCC
#    if __GNUC__ >= 6
#        define CALLABLE_TRAITS_GCC_AT_LEAST_6_0_0
#    endif
#    if __GNUC__ < 5
#        define CALLABLE_TRAITS_GCC_OLDER_THAN_5_0_0
#    endif
#    if __GNUC__ >= 5
#      define CALLABLE_TRAITS_GCC_AT_LEAST_4_9_2
#    elif __GNUC__ == 4 && __GNUC_MINOR__ == 9 && __GNUC_PATCHLEVEL__ >= 2
#      define CALLABLE_TRAITS_GCC_AT_LEAST_4_9_2
#    else
#      define CALLABLE_TRAITS_GCC_OLDER_THAN_4_9_2
#    endif //#if __GNUC__ >= 5
#  endif //#if defined __GNUC__
#endif //#ifndef __clang__

#ifdef _MSC_VER
#  ifdef __clang__
#    define CALLABLE_TRAITS_CLANG_C2
#  else
#    define CALLABLE_TRAITS_MSVC
#  endif // #ifdef __clang__
#endif // #ifdef _MSC_VER

#define CALLABLE_TRAITS_IX_SEQ(...) ::std::index_sequence< __VA_ARGS__ >
#define CALLABLE_TRAITS_MAKE_IX_SEQ(...) ::std::make_index_sequence< __VA_ARGS__ >
#define CALLABLE_TRAITS_DISJUNCTION(...) ::std::disjunction< __VA_ARGS__ >
#define CALLABLE_TRAITS_CONJUNCTION(...) ::std::conjunction< __VA_ARGS__ >

#ifndef __cpp_variable_templates
#  define CALLABLE_TRAITS_DISABLE_VARIABLE_TEMPLATES
#endif

#ifndef __cpp_lib_logical_traits
#  include <boost/callable_traits/detail/polyfills/conjunction.hpp>
#  include <boost/callable_traits/detail/polyfills/disjunction.hpp>
#endif //__cpp_lib_logical_traits

#ifndef __cpp_lib_integer_sequence
#  include <boost/callable_traits/detail/polyfills/make_index_sequence.hpp>
#endif // __cpp_lib_integer_sequence

#if defined(CALLABLE_TRAITS_MSVC) && !defined(BOOST_DISABLE_WIN32)
#  define CALLABLE_TRAITS_DEFAULT_VARARGS_CC __cdecl
#  define CALLABLE_TRAITS_PMF_VARGARGS_CDECL_DEFAULT
#else
#  define CALLABLE_TRAITS_DEFAULT_VARARGS_CC
#endif // #if defined(CALLABLE_TRAITS_MSVC) && !defined(BOOST_DISABLE_WIN32))

#if defined(CALLABLE_TRAITS_GCC) && !defined(CALLABLE_TRAITS_GCC_AT_LEAST_4_9_2) || defined(__INTEL_COMPILER)
#  define CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
#  define CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS
#endif // #if defined CALLABLE_TRAITS_GCC && !defined(CALLABLE_TRAITS_GCC_AT_LEAST_4_9_2)

#ifdef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS
#  define CALLABLE_TRAITS_ABOMINABLE_CONST CALLABLE_TRAITS_EMPTY
#  define CALLABLE_TRAITS_ABOMINABLE_VOLATILE CALLABLE_TRAITS_EMPTY
#else
#  define CALLABLE_TRAITS_ABOMINABLE_CONST const
#  define CALLABLE_TRAITS_ABOMINABLE_VOLATILE volatile
#endif // #ifdef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS

#ifdef CALLABLE_TRAITS_ENABLE_NOEXCEPT_TYPES
#  define CALLABLE_TRAITS_NOEXCEPT_SPECIFIER noexcept
#else
#  define CALLABLE_TRAITS_NOEXCEPT_SPECIFIER CALLABLE_TRAITS_EMPTY
#endif // #ifdef CALLABLE_TRAITS_ENABLE_NOEXCEPT_TYPES

#endif //#ifndef CALLABLE_TRAITS_CONFIG_HPP
