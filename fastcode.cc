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
#include <type_traits>
#include <new> 

template<typename T1, typename T2>
class MyVariant {
public:
    MyVariant() { currentIndex = -1; }    
    ~MyVariant() { reset(); }

    void set(const T1& value) { reset(); new (&t1) T1(value); currentIndex = 0; }
    void set(const T2& value) { reset(); new (&t2) T2(value); currentIndex = 1; }
    int index() const { return currentIndex; }

    T1 get_as_T1() const { if (currentIndex != 0) { throw std::runtime_error("Wrong type"); } return t1; }

    T2 get_as_T2() const { if (currentIndex != 1) { throw std::runtime_error("Wrong type"); } return t2; }

private:
    void reset() { if (currentIndex == 0) { t1.~T1(); } else if (currentIndex == 1) { t2.~T2(); } currentIndex = -1; }
    union { T1 t1; T2 t2; };
    int currentIndex;
};
#include <cstdint>
#include <type_traits>

template <char C, std::uint32_t PrevHash>
struct CompileTimeHashChar { static constexpr std::uint32_t value = (PrevHash * 31) + static_cast<std::uint32_t>(C); };
template <std::uint32_t PrevHash>
struct CompileTimeHashChar<'\0', PrevHash> { static constexpr std::uint32_t value = PrevHash; };

template <const char *Str, std::size_t N, std::uint32_t PrevHash = 0>
struct CompileTimeHash {
    static constexpr std::uint32_t value =  
        CompileTimeHash<Str, N - 1, CompileTimeHashChar<Str[N - 1], PrevHash>::value>::value;
};

template <const char *Str, std::uint32_t PrevHash>
struct CompileTimeHash<Str, 0, PrevHash> { static constexpr std::uint32_t value = PrevHash; };
static constexpr const char test_str[] = "hello";
static constexpr std::uint32_t hash_value = CompileTimeHash<test_str, sizeof(test_str) - 1>::value;
static_assert(hash_value != 0, "Hash calculation failed!");
