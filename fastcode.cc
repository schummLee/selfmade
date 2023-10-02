#include <string>
#include <iostream>
#include <type_traits>

template <typename T>
T sum_impl(T arg) { return arg; }
std::string sum_impl(const std::string& arg) { return arg; }

template <typename T, typename... Args, std::enable_if_t<std::is_arithmetic<T>::value, int> = 0>
T sum_impl(T arg, Args... args) { return arg + sum_impl(args...); }

template <typename... Args, std::enable_if_t<(std::is_same_v<Args, std::string> && ...), int> = 0>
std::string sum_impl(Args... args) { return (... + args); }

template <typename T, typename... Args>
auto sum(T arg1, Args... args) -> decltype(sum_impl(arg1, args...)) {
    static_assert((std::is_same_v<T, Args> && ...), "All types must be the same!");
    return sum_impl(arg1, args...);
}
