
/*
Copyright Barrett Adair 2016

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)

*/

#include <callable_traits/function_type.hpp>
#include "test.hpp"

struct foo;

int main() {

    assert_sfinae<callable_traits::function_type_t, int>();
    assert_sfinae<callable_traits::function_type_t, int &>();
    assert_sfinae<callable_traits::function_type_t, int (foo::* &)()>();
    assert_sfinae<callable_traits::function_type_t, int (foo::* const)()>();
    assert_sfinae<callable_traits::function_type_t, int (foo::* const &)()>();
    assert_sfinae<callable_traits::function_type_t, int (foo::* volatile)()>();

    auto lambda = [](){};
    assert_sfinae<callable_traits::function_type_t, decltype(lambda)&>();
    assert_sfinae<callable_traits::function_type_t, void>();
}

