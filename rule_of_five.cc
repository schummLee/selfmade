#include <cstring>
class RuleOfFive {
    char* str;
public:
    RuleOfFive(const char* val) : str(new char[std::strlen(val) + 1]) {std::strcpy(str, val);}
    RuleOfFive(const RuleOfFive& other) : str(new char[std::strlen(other.str) + 1]) {
        std::strcpy(str, other.str);
    }
    RuleOfFive(RuleOfFive&& other) noexcept : str(std::exchange(other.str, nullptr)) { }
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this == &other) return *this;
        delete[] str;
        str = new char[std::strlen(other.str) + 1];
        std::strcpy(str, other.str);
        return *this;
    }
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {std::swap(str,other.str);return *this;}
    ~RuleOfFive() { delete[] str; }
};
#include <type_traits>
#include <iostream>
template <typename T, std::enable_if_t<std::is_integral<T>::value, int> = 0>
void function(T val) { std::cout << "Integer: " << val << std::endl; }
template <typename T, std::enable_if_t<std::is_floating_point<T>::value, int> = 0>
void function(T val) { std::cout << "Floating point: " << val << std::endl; }
constexpr int factorial(int n) { if (n <= 1) return 1; return n * factorial(n - 1); }
#include <iostream>
void print() { std::cout << std::endl; }
template <typename T, typename... Args>
void print(T first, Args... args) { std::cout << first << " "; print(args...); }
#include <iostream>
#include <memory>
int main() {
    auto ptr = std::make_unique<int>(42);
    auto lambda = [captured_ptr = std::move(ptr)]() {
        std::cout << "Captured value: " << *captured_ptr << std::endl;
    };
    lambda();
}


