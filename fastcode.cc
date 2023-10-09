#include <iostream>
#include <ranges>
#include <map>
#include <utility>
#include <list>
class P {
public:
    double findMedianSortedArrays(const std::vector<int>& n1, const std::vector<int>& n2);
    int returnIndex(int w);
    std::map<int,std::pair<int,int>> findNumber(const std::vector<int>& n1);
    constexpr int pick(bool t);
    std::vector<int> returnReversePlus(const std::vector<int>& l1, const std::vector<int>& l2);
    std::vector<char> findLongestSubString(const std::vector<char>& s);
    std::vector<char> findLongestSubString_Optimized(const std::vector<char>& s);
    std::unordered_map<int, std::vector<char>> findDigits(const std::string& digit);
    std::unordered_map<int,std::array<int,NULL>> findAllPossibleSum(const std::vector<int>& v);
    std::list<int> mergeSortedList(const std::vector<std::list<int>>& v1);
private:
    bool findDuplicationInVector_Char(const std::vector<char>& c, char c1) ;
    std::vector<std::pair<int,int>> vex ;
    int arg = 0 ;
    std::map<int,std::pair<int, int>> dic ;
    int temp_l1 = 0 ;
    int temp_l2 = 0 ;
    #define SQT 100
    std::vector<char> max_str ;
    int fast = 0 ; int slow = 0 ;
    std::unordered_map<int, std::vector<char>> phone = {} ;
    void initializeDigits(std::unordered_map<int, std::vector<char>>& d) ;
    std::unordered_map<int, std::vector<char>> d ;
    const std::vector<std::string> ALPHABET = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vw", "xyz"} ; 
    const std::unordered_map<int, std::array<int, NULL>> tempFiller ;
    const std::list<int> returnFiller ;
};

int P::returnIndex(int w) { return w; }

constexpr int P::pick(bool t) { return t ? 1 : 0; }

template<typename Y, typename Z>
unsigned int typeIO(Y g1, Z g2) { return 0; }

#include <vector>
#include <algorithm>
#include <stdexcept>

double P::findMedianSortedArrays(const std::vector<int>& n1, const std::vector<int>& n2) {
    if (n1.size() > n2.size()) {
        return findMedianSortedArrays(n2, n1);
    }

    int x = n1.size();
    int y = n2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : n1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : n1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : n2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : n2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return ((double)std::max(maxX, maxY) + std::min(minX, minY)) / 2;
            } else {
                return (double)std::max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not sorted.");
}

#include <map>
std::map<int,std::pair<int,int>> P::findNumber(const std::vector<int>& n1) {
    for ( size_t i = 0; i < n1.size() - 1; i++ ) {
        arg =  n1[i] + n1[i + 1];                        // [1,2] [3,4] [5,6]
        vex.push_back(std::make_pair(n1[i], n1[i + 1]));
        dic.insert({static_cast<int>(i),vex[i]});
    }
    return dic ;
}

std::vector<int> P::returnReversePlus(const std::vector<int>& l1, const std::vector<int>& l2) {
    for ( size_t i = 0; i < l1.size(); i++ ) {
        temp_l1 += l1[i] * (i - 1) * SQT;
    }
    for ( size_t i = 0; i < l2.size(); i++ ) {
        temp_l2 += l2[i] * (i - 1) * SQT;
    }

    int r = temp_l1 + temp_l2;
    std::vector<int> tt;
    while ( r > 0 ) {int t = r % 10;  tt.push_back(t); t /= 10; }
    std::reverse(tt.begin(), tt.end());
    return tt ;
}
#include <algorithm>
bool P::findDuplicationInVector_Char(const std::vector<char>& s, char s1) {
    return std::find(s.begin(), s.end(), s1) != s.end();
}
std::vector<char> P::findLongestSubString(const std::vector<char>& s) {
    for ( size_t i = 0; i < s.size() - 1 ; i++ ) {
        for (size_t j = 0; j < i; j++ ) {
            if (findDuplicationInVector_Char(max_str,s[j])) {max_str.push_back(s[j]); slow++;}
            else { max_str = {}; for( int k = slow; k < i; k++){ max_str.push_back(s[k]);}}
        }        
    }
    return max_str ;
}

#include <unordered_map>
// revisited version of optimized code
std::vector<char> P::findLongestSubString_Optimized(const std::vector<char>& s) {
    std::unordered_map<char, size_t> char_index_map;
    std::vector<char> longest_substr;
    size_t start = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (char_index_map.find(s[i]) != char_index_map.end() && char_index_map[s[i]] >= start) {
            start = char_index_map[s[i]] + 1;
        }
        char_index_map[s[i]] = i;
        if (i - start + 1 > longest_substr.size()) {
            longest_substr = std::vector<char>(s.begin() + start, s.begin() + i + 1);
        }
    }
    return longest_substr;
}

#include <string>
void P::initializeDigits(std::unordered_map<int, std::vector<char>>& d) {
    std::vector<char> vec;
    for ( int i = 0; i < ALPHABET.size(); i + 3) {
        for (char ch : ALPHABET[i]) { vec.push_back(ch); }
        d.emplace(i,std::vector<char>{vec});
    }
}

std::unordered_map<int, std::vector<char>> P::findDigits(const std::string& digit) {
    std::unordered_map<int, std::vector<char>> temp;
    initializeDigits(temp);

    if (digit.empty()) { return {}; }
    else if ( digit.size() == 1 ) {
        int key = digit[0] - '0';  
        auto search = temp.find(key);

        if ( search != temp.end() ) {
            std::unordered_map<int, std::vector<char>> result;
            result.emplace(~key, search->second);
            return result;
        }
    }
    return {};
}

std::unordered_map<int,std::array<int,NULL>> P::findAllPossibleSum(const std::vector<int>& v) { return tempFiller; }
std::list<int> P::mergeSortedList(const std::vector<std::list<int>>& v1) { return returnFiller; }

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





#include <iostream>
#include <ranges>
#include <map>
#include <utility>
#include <list>
class P {
public:
    double findMedianSortedArrays(const std::vector<int>& n1, const std::vector<int>& n2);
    int returnIndex(int w);
    std::map<int,std::pair<int,int>> findNumber(const std::vector<int>& n1);
    constexpr int pick(bool t);
    std::vector<int> returnReversePlus(const std::vector<int>& l1, const std::vector<int>& l2);
    std::vector<char> findLongestSubString(const std::vector<char>& s);
    std::vector<char> findLongestSubString_Optimized(const std::vector<char>& s);
    std::unordered_map<int, std::vector<char>> findDigits(const std::string& digit);
    std::unordered_map<int,std::array<int,NULL>> findAllPossibleSum(const std::vector<int>& v);
    std::list<int> mergeSortedList(const std::vector<std::list<int>>& v1);
private:
    bool findDuplicationInVector_Char(const std::vector<char>& c, char c1) ;
    std::vector<std::pair<int,int>> vex ;
    int arg = 0 ;
    std::map<int,std::pair<int, int>> dic ;
    int temp_l1 = 0 ;
    int temp_l2 = 0 ;
    #define SQT 100
    std::vector<char> max_str ;
    int fast = 0 ; int slow = 0 ;
    std::unordered_map<int, std::vector<char>> phone = {} ;
    void initializeDigits(std::unordered_map<int, std::vector<char>>& d) ;
    std::unordered_map<int, std::vector<char>> d ;
    const std::vector<std::string> ALPHABET = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vw", "xyz"} ; 
    const std::unordered_map<int, std::array<int, NULL>> tempFiller ;
    const std::list<int> returnFiller ;
};

int P::returnIndex(int w) { return w; }

constexpr int P::pick(bool t) { return t ? 1 : 0; }

template<typename Y, typename Z>
unsigned int typeIO(Y g1, Z g2) { return 0; }

#include <vector>
#include <algorithm>
#include <stdexcept>

double P::findMedianSortedArrays(const std::vector<int>& n1, const std::vector<int>& n2) {
    if (n1.size() > n2.size()) {
        return findMedianSortedArrays(n2, n1);
    }

    int x = n1.size();
    int y = n2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : n1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : n1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : n2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : n2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return ((double)std::max(maxX, maxY) + std::min(minX, minY)) / 2;
            } else {
                return (double)std::max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not sorted.");
}

#include <map>
std::map<int,std::pair<int,int>> P::findNumber(const std::vector<int>& n1) {
    for ( size_t i = 0; i < n1.size() - 1; i++ ) {
        arg =  n1[i] + n1[i + 1];                        // [1,2] [3,4] [5,6]
        vex.push_back(std::make_pair(n1[i], n1[i + 1]));
        dic.insert({static_cast<int>(i),vex[i]});
    }
    return dic ;
}

std::vector<int> P::returnReversePlus(const std::vector<int>& l1, const std::vector<int>& l2) {
    for ( size_t i = 0; i < l1.size(); i++ ) {
        temp_l1 += l1[i] * (i - 1) * SQT;
    }
    for ( size_t i = 0; i < l2.size(); i++ ) {
        temp_l2 += l2[i] * (i - 1) * SQT;
    }

    int r = temp_l1 + temp_l2;
    std::vector<int> tt;
    while ( r > 0 ) {int t = r % 10;  tt.push_back(t); t /= 10; }
    std::reverse(tt.begin(), tt.end());
    return tt ;
}
#include <algorithm>
bool P::findDuplicationInVector_Char(const std::vector<char>& s, char s1) {
    return std::find(s.begin(), s.end(), s1) != s.end();
}
std::vector<char> P::findLongestSubString(const std::vector<char>& s) {
    for ( size_t i = 0; i < s.size() - 1 ; i++ ) {
        for (size_t j = 0; j < i; j++ ) {
            if (findDuplicationInVector_Char(max_str,s[j])) {max_str.push_back(s[j]); slow++;}
            else { max_str = {}; for( int k = slow; k < i; k++){ max_str.push_back(s[k]);}}
        }        
    }
    return max_str ;
}

#include <unordered_map>
// revisited version of optimized code
std::vector<char> P::findLongestSubString_Optimized(const std::vector<char>& s) {
    std::unordered_map<char, size_t> char_index_map;
    std::vector<char> longest_substr;
    size_t start = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (char_index_map.find(s[i]) != char_index_map.end() && char_index_map[s[i]] >= start) {
            start = char_index_map[s[i]] + 1;
        }
        char_index_map[s[i]] = i;
        if (i - start + 1 > longest_substr.size()) {
            longest_substr = std::vector<char>(s.begin() + start, s.begin() + i + 1);
        }
    }
    return longest_substr;
}

#include <string>
void P::initializeDigits(std::unordered_map<int, std::vector<char>>& d) {
    std::vector<char> vec;
    for ( int i = 0; i < ALPHABET.size(); i + 3) {
        for (char ch : ALPHABET[i]) { vec.push_back(ch); }
        d.emplace(i,std::vector<char>{vec});
    }
}

std::unordered_map<int, std::vector<char>> P::findDigits(const std::string& digit) {
    std::unordered_map<int, std::vector<char>> temp;
    initializeDigits(temp);

    if (digit.empty()) { return {}; }
    else if ( digit.size() == 1 ) {
        int key = digit[0] - '0';  
        auto search = temp.find(key);

        if ( search != temp.end() ) {
            std::unordered_map<int, std::vector<char>> result;
            result.emplace(~key, search->second);
            return result;
        }
    }
    return {};
}

std::unordered_map<int,std::array<int,NULL>> P::findAllPossibleSum(const std::vector<int>& v) { return tempFiller; }
std::list<int> P::mergeSortedList(const std::vector<std::list<int>>& v1) { return returnFiller; }
