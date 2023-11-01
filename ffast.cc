#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <type_traits>

template<typename A, typename B> std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename std::enable_if< !std::is_same<T_container, std::string>::value, typename T_container::value_type>::type>
std::ostream& operator<<(std::ostream& os, const T_container& v) { os << '{'; std::string sep; for (const T& x : v) { os << sep << x; sep = ", "; } return os << '}'; }
#ifdef LOCAL
#define dbg(...) std::cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { std::cerr << std::endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { std::cerr << ' ' << H; dbg_out(T...); }
#else
#define dbg(...)
#endif
// -----------------------------------------------------------------------------------------------------------------------------------
using ll = long long ; using ld = long double ;

constexpr int MAX_N = static_cast<int>(1e5) + 5 ;
constexpr ll MOD =     static_cast<ll>(1e9) + 7 ;
constexpr ll INF =         static_cast<ll>(1e9) ;
constexpr ld EPS =                         1e-9 ;

int n, m ; std::array<int, MAX_N> vis ; std::array<std::vector<int>, MAX_N> adj ; 
void dfs(int u) { vis[u] = 1; for (const int v : adj[u]) { if (vis[v]) continue; dfs(v); } }
// ----------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>

#include <list>
#include <set>
#include <algorithm>
#include <iterator>
// ----------------------------------------------------------------------------------------------------------------------------------
template<typename Container, typename Element> bool customContain(const Container& container, const Element& element) { return std::find(std::begin(container), std::end(container), element) != std::end(container); }

unsigned int firstMissingPositive(std::vector<int>& nums) { unsigned int tmp = 1; const auto size = nums.size();  for (unsigned int i = 1; i <= size + 1; ++i) { if (!customContain(nums,tmp)) { tmp = i; break; } } return tmp; }
unsigned int q;
bool isMatch(const std::string& s, const std::string& p) {
    int m = s.length(), n = p.length();
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; ++j) { if (p[j - 1] == '*') { dp[0][j] = dp[0][j - 1]; } }
    for (int i = 1; i <= m; ++i) { for (int j = 1; j <= n; ++j) { if (p[j - 1] == '*') { dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) { dp[i][j] = dp[i - 1][j - 1]; } }  }
	return dp[m][n];
} // 100ms ,11mb slow 10% : 60 %
bool isMatch_greedy(const std::string &s, const std::string &p) {
    int i = 0, j = 0, starIndex = -1, iIndex = -1, m = s.size(), n = p.size();
    while (i < m) { if (j < n && (s[i] == p[j] || p[j] == '?')) { ++i; ++j; } else if (j < n && p[j] == '*') { starIndex = j; iIndex = i; ++j; } else if (starIndex == -1) { return false; } else { j = starIndex + 1; i = iIndex + 1; iIndex = i; } }
    while (j < n && p[j] == '*') { ++j; }
    return j == n;
} // 6ms ,6.67mb fast 97% : 97%
void permute(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start == nums.size() - 1) { result.push_back(nums); return; }
    for (int i = start; i < nums.size(); ++i) { std::swap(nums[start], nums[i]); permute(nums, start + 1, result); std::swap(nums[start], nums[i]); }
}
std::vector<std::vector<int>> permute(std::vector<int>& nums) { std::vector<std::vector<int>> result; permute(nums, 0, result); return result; }
void permuteHelper(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start == nums.size() - 1) { result.emplace_back(nums); return; }
    for (int i = start; i < nums.size(); ++i) { std::swap(nums[start], nums[i]); permuteHelper(nums, start + 1, result); std::swap(nums[start], nums[i]); }
}
std::vector<std::vector<int>> permute_H(std::vector<int> nums) { std::vector<std::vector<int>> result; permuteHelper(nums, 0, result); return result; }
std::vector<std::vector<int>> matrix = {};
void rotate(std::vector<std::vector<int>>& matrix) { int n = matrix.size(); for(int i = 0; i < n; ++i) { for(int j = i; j < n; ++j) { std::swap(matrix[i][j], matrix[j][i]); } }for(int i = 0; i < n; ++i) { std::reverse(matrix[i].begin(), matrix[i].end()); } }
#include <unordered_map>
std::vector<std::vector<char*>> chr = {}; std::vector<std::vector<std::string>> return_str = {};
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
    std::vector<std::vector<std::string>> return_str;
    for (size_t i = 0; i < strs.size(); ++i) { 
		std::string sortedStr = strs[i]; 
		std::sort(sortedStr.begin(), sortedStr.end());
		if (anagramGroups.find(sortedStr) == anagramGroups.end()) { anagramGroups[sortedStr] = std::vector<std::string>(); } 
		anagramGroups[sortedStr].push_back(strs[i]);
    }
    for (const auto& [key, val] : anagramGroups) { return_str.push_back(val); }
    return return_str;
}
std::vector<std::vector<std::string>> groupAnagrams_approach(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
	std::vector<std::vector<std::string>> result;
    for (const auto& str : strs) { std::string sortedStr = str; std::sort(sortedStr.begin(), sortedStr.end()); anagramGroups[sortedStr].push_back(str); }
    for (const auto& [_, group] : anagramGroups) { result.push_back(group); }
	return result;
}
#include <cmath>
double myPow(double x, int n) { if (n == 0) { return 1.0; } if (n == 1) { return x; } if (n == -1) { return 1.0 / x; } double half = myPow(x, n / 2); if (n % 2 == 0) { return half * half; } else { return half * half * (n > 0 ? x : 1.0 / x); }  }
#include <unordered_map>
bool isSafe(const std::vector<int>& board, int row, int col) { for (int i = 0; i < row; ++i) { if(board[i] == col || std::abs(board[i] - col) == std::abs(i - row)) { return false; } } return true; }
void backtrack(std::vector<std::vector<std::string>>& solutions, std::vector<int>& board, int row, int n) {
    if (row == n) { std::vector<std::string> result; for (int i = 0; i < n; ++i) { std::string rowString(n, '.'); rowString[board[i]] = 'Q'; result.push_back(rowString); } solutions.push_back(result); return; }
    for (int col = 0; col < n; ++col) { if (isSafe(board, row, col)) { board[row] = col; backtrack(solutions, board, row + 1, n); } }
}
std::vector<std::vector<std::string>> solveNQueens(int n) { std::vector<std::vector<std::string>> solutions; std::vector<int> board(n, -1); backtrack(solutions, board, 0, n); return solutions; }
std::unordered_map<int,std::vector<int>> slideWindowTypeVector(std::vector<int> vec) { 
	size_t i ; size_t j = vec.size() ; std::unordered_map<int,std::vector<int>> lt; std::vector<int> v = vec;
	for( i = 0 ; i < j ; ++i ) { lt.push_back(v.begin(i),v.end(j)); }
	for( i = j ; i > 0 ; --i ) { lt.push_back(v.begin(0),v.end(i)); }
	return lt;
}
int maxSubArray(const std::vector<int>& nums) { int current = nums[0];int global = nums[0]; for (size_t i = 1; i < nums.size(); ++i) {current = std::max(nums[i], current + nums[i]); if(current > global) {global = current;} } return max_global; }
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result; int m = matrix.size(); int n = matrix[0].size(); int top = 0, bottom = m - 1, left = 0, right = n - 1; bool toR = true, toL = false, toD = false, toU = false;
    while (top <= bottom && left <= right) {
        if (toR) { for (int i = left; i <= right; ++i) { result.push_back(matrix[top][i]); } ++top; toR = false; toD = true; }
        else if (toD) { for (int i = top; i <= bottom; ++i) { result.push_back(matrix[i][right]); } --right; toD = false; toL = true; }
        else if (toL) { for (int i = right; i >= left; --i) { result.push_back(matrix[bottom][i]); } --bottom; toL = false; toU = true; }
        else if (toU) { for (int i = bottom; i >= top; --i) { result.push_back(matrix[i][left]); } ++left; toU = false; toR = true; }
    }
    return result;
}
bool canJump(std::vector<int>& nums) { int maxReach = 0 ; int n = nums.size() ; for( int i = 0; i < n ; ++i ) { if( i > maxReach) { return false ; } maxReach = std::max(maxReach, i + nums[i] ; if ( maxReach >= n - 1 ) { return true ; } } return false ;   } 
#include <vector>
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> vec;
    if (intervals.empty()) { return vec; }
    vec.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) { if (intervals[i][0] <= vec.back()[1]) { vec.back()[1] = std::max(vec.back()[1], intervals[i][1]); } else { vec.push_back(intervals[i]); } }
    return vec;
}
#include <string>
enum class State { START, SIGN, INTEGER, DOT, DECIMAL, EXPONENT, EXPONENT_SIGN, EXPONENT_INT, SPACE, INVALID };
bool isNumber(std::string s) {
    State state = State::START; int n = s.size(); int i = 0;
    while (i < n) {
        char c = s[i];
        switch (state) {
            case State::START: if (c == '+' || c == '-') state = State::SIGN; else if (isdigit(c)) state = State::INTEGER; else if (c == '.') state = State::DOT; else if (c == ' ') state = State::SPACE; else return false; break;
            case State::SIGN: case State::EXPONENT_SIGN: if (isdigit(c)) state = State::INTEGER; else if (c == '.') state = State::DOT; else return false; break;
            case State::INTEGER: if (isdigit(c)) {} else if (c == '.') state = State::DECIMAL; else if (c == 'e' || c == 'E') state = State::EXPONENT; else if (c == ' ') state = State::SPACE; else return false; break;
            case State::DOT: if (isdigit(c)) state = State::DECIMAL; else return false; break;
            case State::DECIMAL: if (isdigit(c)) {} else if (c == 'e' || c == 'E') state = State::EXPONENT; else if (c == ' ') state = State::SPACE; else return false; break;
            case State::EXPONENT: if (c == '+' || c == '-') state = State::EXPONENT_SIGN; else if (isdigit(c)) state = State::EXPONENT_INT; else return false; break;
            case State::EXPONENT_INT: if (isdigit(c)) {} else if (c == ' ') state = State::SPACE; else return false; break;
            case State::SPACE: if (c == ' ') {} else return false; break;
            default: return false;
        }
        i++;
    }
    return (state == State::INTEGER || state == State::DECIMAL || state == State::EXPONENT_INT);
}
std::vector<int> plusOne(std::vector<int>& digits) {int carry = 1; for(int i = digits.size()-1; i>=0; --i){int sum = digits[i] + carry;digits[i] = sum % 10;carry = sum/10;if(carry=0){break;}if(carry>0) {digits.insert(digits.begin(), carry);} return digits;}
std::string addBinary(const std::string& a, const std::string& b) {
    int carry = 0; std::string result = ""; int i = a.size() - 1; int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) { int bitA = (i >= 0) ? a[i] - '0' : 0; int bitB = (j >= 0) ? b[j] - '0' : 0; int sum = bitA + bitB + carry; carry = sum / 2; int bitSum = sum % 2; result = std::to_string(bitSum) + result; i--; j--; }
    return result;
}
std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> result; int currentWidth = 0; int startIndex = 0;
    for (int i = 0; i < words.size(); ++i) { 
		if (currentWidth + words[i].length() + i - startIndex > maxWidth) { int totalSpaces = maxWidth - currentWidth; int numGaps = i - startIndex - 1; std::string line = words[startIndex];
            if (numGaps == 0) { line += std::string(totalSpaces, ' '); } 
			else { int spacesPerGap = totalSpaces / numGaps; int extraSpaces = totalSpaces % numGaps; for (int j = startIndex + 1; j < i; ++j) { line += std::string(spacesPerGap, ' '); if (extraSpaces > 0) { line += ' '; extraSpaces--; } line += words[j]; }
    	}
            result.push_back(line);
            startIndex = i;
            currentWidth = words[i].length();
        } else { currentWidth += words[i].length(); }
    }
    std::string lastLine = words[startIndex];
    for (int i = startIndex + 1; i < words.size(); ++i) { lastLine += ' ' + words[i]; }
    lastLine += std::string(maxWidth - lastLine.length(), ' ');
    result.push_back(lastLine);
    return result;
}
int minClipsToCover(std::vector<std::vector<int>>& clips, int time) 
{
    std::vector<int> dp(time + 1, time + 2); dp[0] = 0;
    for (int t = 1; t <= time; ++t) { for (const std::vector<int>& clip : clips) { int start = clip[0]; int end = clip[1]; if (start < t && t <= end) { dp[t] = std::min(dp[t], dp[start] + 1); } } }
    return (dp[time] == time + 2) ? -1 : dp[time];
}

int main() {
void solve() {  }

//
// template for code practice and fun exploitation									   																																												
// see asm with otool -tv filename > targetFile.s ( use in M-series chips only )	   																																												
// write by george sequence list problem solving utility 09/10/23 - pacific time EST  																																												
// run with clang++ --std=c++23 or --std=c++20 :/ with ffast.cc -o ff -v			   																																												
// 
auto main() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); int tc = 1;
    for (int t = 1; t <= tc; ++t) { solve(); }
    std::vector<std::vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    rotate(matrix);
     
    for (const auto& row : matrix) { for (const auto& element : row) { std::cout << element << ' '; }  std::cout << std::endl; }
    return 0;
}






















