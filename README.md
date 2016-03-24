<!--
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
-->

# CallableTraits

[![Join the chat at https://gitter.im/badair/callable_traits](https://badges.gitter.im/badair/callable_traits.svg)](https://gitter.im/badair/callable_traits?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

<!--![Build Status](https://travis-ci.org/badair/CLBL.svg?branch=master)-->

<!--[![Join the chat at https://gitter.im/badair/CLBL](https://badges.gitter.im/badair/CLBL.svg)](https://gitter.im/badair/CLBL?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) -->

<!--</a> <a target="_blank" href="http://melpon.org/wandbox/permlink/TlioDiz6yYNxZFnv">![Try it online][badge.wandbox]</a>-->

Note: This is a work-in-progress.

## Overview
<!-- Important: keep this in sync with example/intro.cpp -->
```cpp

#include <type_traits>
#include <functional>
#include <tuple>
#include <callable_traits/callable_traits.hpp>

// This example uses a function object. All features shown in this example
// can be used for other callable types, including (but not limited to) function
// pointers and member function pointers. Ambiguous callables (e.g. function
// objects with templated/overloaded operator()) are not discussed in this example.

struct foo {
    void operator()(int, char, float, void* = nullptr) const {}
};

namespace ct = callable_traits;
using namespace std::placeholders;

int main() {

    // indexed argument types
    using second_arg = ct::arg_at<1, foo>;
    static_assert(std::is_same<second_arg, char>{}, "");

    // arguments in a tuple
    using args = ct::args<foo>;
    using expected_args = std::tuple<int, char, float, void*>;
    static_assert(std::is_same<args, expected_args>{}, "");

    //callable_traits::result_of is a bit friendlier than std::result_of 
    using return_type = ct::result_of<foo>;
    static_assert(std::is_same<return_type, void>{}, "");

    // callable_traits::signature yields a plain function type
    using signature = ct::signature<foo>;
    using expected_signature = void(int, char, float, void*);
    static_assert(std::is_same<signature, expected_signature>{}, "");

    // when trait information can be conveyed in an integral_constant,
    // callable_traits uses functions instead of template aliases.
    // The line below could use ct::arity<foo>() instead. This applies
    // to all function-style type traits. Note: min_arity and max_arity
    // only differ from arity when the argument is a function object.
    static_assert(ct::arity(foo{}) == 4, "");
    static_assert(ct::max_arity(foo{}) == 4, "");
    static_assert(ct::min_arity(foo{}) == 3, "");

    // C-style varargs (`...` in a signature) can be detected.
    static_assert(!ct::has_varargs(foo{}), "");

    // callable_traits::is_ambiguous yields std::true_type 
    // only when the callable is overloaded or templated.
    static_assert(!ct::is_ambiguous(foo{}), "");

    // callable_traits::can_invoke allows us to preview whether
    // std::invoke will compile with the given arguments. Keep
    // in mind that failing cases must be SFINAE-friendly (i.e.
    // any failing static_asserts can still be tripped). Note: The
    // same is true for min_arity and max_arity on function objects.
    static_assert(ct::can_invoke(foo{}, 1, 'a', 3.0), "");
    // no error:     std::invoke(foo{}, 1, 'a', 3.0);

    static_assert(!ct::can_invoke(foo{}, nullptr), "");
    // error:         std::invoke(foo{}, nullptr);

    // callable_traits::bind_expr parses bind expressions. Nested bind
    // expressions are also handled, but are not shown in this example.
    using bind_expression = decltype(ct::bind_expr(foo{}, _1, _1, _1));

    // int is chosen as the expected argument for the bind expression
    // because it's the best fit for all three placeholder slots.
    static_assert(std::is_same<
        ct::args<bind_expression>,
        std::tuple<int>
    >{}, "");

    // Unfortunately, we can't do type manipulations with std::bind directly,
    // because the ISO C++ standard says very little about the return type of
    //std::bind. So, we call std::bind in the same way we called ct::bind_expr
    // above. If there is interest within Boost, this functionality can be
    // integrated into Boost.Bind (on which this implementation is loosely based).
    auto bind_obj = std::bind(foo{}, _1, _1, _1);

    // callable_traits can facilitate the construction of std::function objects.
    auto fn = std::function<ct::signature<bind_expression>>{ bind_obj };
    fn(0);

    // For function objects, the following checks are determined by the 
    // qualifiers on operator(). For member function pointers and abominable
    // function types, the qualifier on the function type are used.
    static_assert(ct::is_const_qualified(foo{}), "");
    static_assert(!ct::is_volatile_qualified(foo{}), "");
    static_assert(!ct::is_reference_qualified(foo{}), "");
    static_assert(!ct::is_lvalue_reference_qualified(foo{}), "");
    static_assert(!ct::is_rvalue_reference_qualified(foo{}), "");

    return 0;
}
```

## License
Please see [LICENSE.md](LICENSE.md).

<!-- Links -->
[badge.Wandbox]: https://img.shields.io/badge/try%20it-online-blue.svg
[example.Wandbox]: http://melpon.org/wandbox/permlink/TlioDiz6yYNxZFnv
