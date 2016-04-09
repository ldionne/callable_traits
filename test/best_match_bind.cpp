/*

Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#include <cassert>
#include <type_traits>
#include <functional>
#include <iostream>
#include <sstream>
#include <memory>
#include <iostream>
#include <cstdint>
#include <callable_traits/callable_traits.hpp>

#ifndef CT_ASSERT
#define CT_ASSERT(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#endif //CT_ASSERT

using namespace std::placeholders;
namespace ct = callable_traits;

struct Vampire {};
struct Robot {};
struct Animal {};
struct Dog : Animal {};
struct Poodle : Dog {};
struct VampireRobotPoodle : Poodle, Robot, Vampire {};


auto take_vampire(const Vampire&) {
    return 0;
}

auto take_robot(const Robot&) {
    return 0;
}

auto take_dog(const Dog&) {
    return 0;
}

auto take_vampire_robot_poodle(const VampireRobotPoodle&) {
    return 0;
}

int foo(int, int, int, int) {
    return 0;
}

int main() {

    {
        auto b = ct::bind(
            foo,
            ct::bind(take_vampire, _1),
            ct::bind(take_robot, _1),
            ct::bind(take_dog, _1),
            ct::bind(take_vampire_robot_poodle, _1)
        );

        using args = ct::args<decltype(b)>;
        using expected_args = std::tuple<const VampireRobotPoodle&>;
        CT_ASSERT(std::is_same<args, expected_args>::value);
        
        VampireRobotPoodle vampire_robot_poodle;
        assert(b(vampire_robot_poodle) == 0);
    }

    {
        auto b = ct::bind(
            foo,
            ct::bind(take_vampire_robot_poodle, _1),
            ct::bind(take_vampire, _1),
            ct::bind(take_robot, _1),
            ct::bind(take_dog, _1)
        );

        using args = ct::args<decltype(b)>;
        using expected_args = std::tuple<const VampireRobotPoodle&>;
        CT_ASSERT(std::is_same<args, expected_args>::value);

        VampireRobotPoodle vampire_robot_poodle;
        assert(b(vampire_robot_poodle) == 0);
    }

    return 0;
}
