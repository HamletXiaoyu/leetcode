// utl_string.cpp --- 
// Filename: utl_string.cpp
// Created: Tue Aug 28 22:30:35 2018 (+0800)
// 
// 
// Copyright Hamlet zheng.
// 
// 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
// copyright部分和本使用声明部分，除非显示声明，copyright的持有者
// 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
// 
// THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
// EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
// DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
// TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// 

#include "utl_string.h"
#include <vector>
#include <map>

using namespace std;

string z_convert(string& s, int rows)
{
    if (rows <= 1)
        return s;
    string res = "";
    int size = 2 * rows - 2;
    for (int i = 0; i < rows; ++i) {
        for (int j = i; j < s.size(); j += size) {
            res += s[j];
            int tmp = j + size - 2 * i;
            if (i != 0 && i != rows - 1 && tmp < s.size())
                res += s[tmp];
        }
    }
    return res;
}

int roman_to_int(string s)
{
    int ret = 0, i = 0;
    int cnt = s.size();
    while (i < cnt) {
        if (s[i] == 'M') {
            ret += 1000;
            i += 1;
        } else if ( s[i] == 'D') {
            ret += 500;
            i += 1;
        } else if ( s[i] == 'C') {
            if ( i != cnt -1 && s[i+1] == 'D') {
                ret += 400;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'M') {
                ret += 900;
                i += 2;
            } else {
                ret += 100;
                i += 1;
            }
        }else if (s[i] == 'L') {
            ret += 50;
            i += 1;
        } else if ( s[i] == 'X') {
            if ( i != cnt -1 && s[i+1] == 'L') {
                ret += 40;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'C') {
                ret += 90;
                i += 2;
            } else {
                ret += 10;
                i += 1;
            }
        } else if ( s[i] == 'V') {
            ret += 5;
            i += 1;
        } else if ( s[i] == 'I') {
            if ( i != cnt -1 && s[i+1] == 'V') {
                ret += 4;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'X') {
                ret += 9;
                i += 2;
            } else {
                ret += 1;
                i += 1;
            }
        }
    }
    return ret;
}

string int_to_roman(int num)
{
    string res = "";
    string v1[] = {"", "M", "MM", "MMM"};
    string v2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string v3[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string v4[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
}

int length_of_lastword(string s)
{
    int right = s.size() - 1, res = 0;
    while (right >= 0 && s[right] == ' ')
        --right;
    while (right >= 0 && s[right] != ' ' ) {
        --right; 
        ++res;
    }
    return res;
}

string multiply(string num1, string num2)
{
    string res;
    int n1 = num1.size(), n2 = num2.size();
    int k = n1 + n2 - 2, carry = 0;
    vector<int> v(n1 + n2, 0);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (int i = 0; i < n1 + n2; ++i) {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] %= 10;
    }
    int i = n1 + n2 - 1;
    while (v[i] == 0)
        --i;
    if (i < 0)
        return "0";
    while (i >= 0)
        res.push_back(v[i--] + '0');
    return res;
}

string add_strings(string num1, string num2)
{
    string res = "";
    int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 || j >= 0) {
        int a = i >= 0 ? num1[i--] - '0' : 0;
        int b = j >= 0 ? num2[j--] - '0' : 0;
        int sum = a + b + carry;
        res.insert(res.begin(), sum % 10 + '0');
        carry = sum / 10;
    }
    return carry ? "1" + res : res;
}

string longest_common_prefix(vector<string>& strs)
{
    if (strs.empty()) 
        return "";
    string res = "";
    for (int j = 0; j < strs[0].size(); ++j) {
        char c = strs[0][j];
        for (int i = 1; i < strs.size(); ++i) {
            if (j >= strs[i].size() || strs[i][j] != c) {
                return res;
            }
        }
        res.push_back(c);
    }
    return res;
}

bool judge_circle(string moves)
{
    int a[] = {0, 0};
    for (int i = 0; i< moves.size(); ++i) {
        if (moves[i] == 'L')
            a[0] -= 1;
        else if (moves[i] == 'R')
            a[0] += 1;
        else if (moves[i] == 'U')
            a[1] += 1;
        else if (moves[i] == 'D')
            a[1] -= 1;
    }
    if (a[0] == 0 && a[1] == 0)
        return true;
    else
        return false;
}

string add_binary(string a, string b)
{
    string res = "";
    int m = a.size() - 1, n = b.size() - 1, carry = 0;
    while (m >= 0 || n >= 0) {
        int p = m >= 0 ? a[m--] - '0' : 0;
        int q = n >= 0 ? b[n--] - '0' : 0;
        int sum = p + q + carry;
        res = to_string(sum % 2) + res;
        carry = sum / 2;
    }
    return carry == 1 ? "1" + res : res;   
}

void helper(string s, int n, string out, vector<string>& res)
{
    if (n == 4) {
        if (s.empty()) 
            res.push_back(out);
    } else {
        for (int k = 1; k < 4; ++k) {
            if (s.size() < k) 
                break;
            int val = atoi(s.substr(0, k).c_str());
            if (val > 255 || k != std::to_string(val).size()) 
                continue;
            helper(s.substr(k), n + 1,
                   out + s.substr(0, k) + (n == 3 ? "" : "."), res);
        }
    }
}

vector<string> restore_ips(string s)
{
    vector<string> res;
    helper(s, 0, "", res);
    return res;
}

int first_uniq_char(string s)
{
    vector<int> m(26, 0);
    // int a[26] = {0};
    for (int i = 0; i < s.size(); ++i)
        m[s[i] - 'a']++;
            
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i] - 'a'] == 1) 
            return i;
    }
    return -1;
}

bool is_number(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

bool is_palindrome_str(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (!is_number(s[i]) && !is_letter(s[i])) {
            i++;
            continue;
        }
        if (!is_number(s[j]) && !is_letter(s[j])) {
            j--;
            continue;
        }
        if (s[i] == s[j] ||
            s[i] - ('a' - 'A') == s[j] ||
            s[i] + ('a' - 'A') == s[j]) {
            i++;
            j--;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int count_segments(string s)
{
    int res = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') 
            continue;
        ++res;
        while (i < n && s[i] != ' ') 
            ++i;
    }
    return res;
}

int compress(vector<char>& chars)
{
    int n = chars.size(), cur = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && chars[j] == chars[i])
            ++j;
        chars[cur++] = chars[i];
        
        if (j - i == 1)
            continue;
        // change int to string
        for (char c : to_string(j - i))
            chars[cur++] = c;
    }
    return cur;
}

int compare_version(string version1, string version2)
{
    int n1 = version1.size(), n2 = version2.size();
    int i = 0, j = 0, d1 = 0, d2 = 0;
    string v1, v2;
    while (i < n1 || j < n2) {
        while (i < n1 && version1[i] != '.') {
            v1.push_back(version1[i++]);
        }
        d1 = atoi(v1.c_str());
        while (j < n2 && version2[j] != '.') {
            v2.push_back(version2[j++]);
        }
        d2 = atoi(v2.c_str());
        if (d1 > d2)
            return 1;
        else if (d1 < d2)
            return -1;
        v1.clear();
        v2.clear();
        ++i;
        ++j;
    }
    return 0;
}

bool is_vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' ||
            c == 'I' || c == 'O' || c == 'U');
}

string reverse_vowels(string s)
{
    int left = 0, right= s.size() - 1;
    while (left < right) {
        if (is_vowel(s[left]) && is_vowel(s[right])) {
            swap(s[left++], s[right--]);
        } else if (is_vowel(s[left])) {
            --right;
        } else {
            ++left;
        }
    }
    return s;
}

bool can_construct(string ransom_note, string magazine)
{
    map<char, int> dict;
    for (int i = 0; i < magazine.size(); ++i) {
        dict[magazine[i]] += 1;
    }
    for (int i = 0; i < ransom_note.size(); ++i) {
        if (--dict[ransom_note[i]] < 0)
            return false;
    }
    return true;
}

bool detect_capitaluse(string word)
{
    int cnt = 0, n = word.size();
    for (int i = 0; i < n; ++i) {
        if (word[i] <= 'Z') ++cnt;
    }
    return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
}

string reverse_str(string s, int k)
{
    for (int i = 0; i < s.size(); i += 2 * k) {
        reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
    }
    return s;
}

int find_lus_length(string a, string b)
{
    return a == b ? -1 : max(a.size(), b.size());
}

bool check_record(string s)
{
    int cntA = 0, cntL = 0;
    for (char c : s) {
        if (c == 'A') {
            if (++cntA > 1)
                return false;
            cntL = 0;
        } else if (c == 'L') {
            if (++cntL > 2)
                return false;
        } else {
            cntL = 0;
        }
    }
    return true;
}

string reverse_words(string s)
{
    int start = 0, end = 0, n = s.size();
    while (start < n && end < n) {
        while (end < n && s[end] != ' ')
            ++end;
        for (int i = start, j = end - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        start = ++end;
    }
    return s;
}

void reverse_words1(string &s)
{
    int storeIndex = 0, n = s.size();
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            if (storeIndex != 0)
                s[storeIndex++] = ' ';
            int j = i;
            while (j < n && s[j] != ' ')
                s[storeIndex++] = s[j++];
            reverse(s.begin() + storeIndex - (j - i),
                    s.begin() + storeIndex);
            i = j;
        }
    }
    s.resize(storeIndex);
}

string convert_hundred(int num)
{
    string v1[] = {"", "One", "Two", "Three", "Four",
                         "Five", "Six", "Seven", "Eight",
                         "Nine", "Ten", "Eleven", "Twelve",
                         "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                         "Seventeen", "Eighteen", "Nineteen"};
    string v2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                         "Sixty", "Seventy", "Eighty", "Ninety"};
    string res;
    int a = num / 100, b = num % 100, c = num % 10;
    res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
    if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
    return res;
}

string number_to_words(int num)
{
    string res = convert_hundred(num % 1000);
    string v[] = {"Thousand", "Million", "Billion"};
    for (int i = 0; i < 3; ++i) {
        num /= 1000;
        res = num % 1000 ? convert_hundred(num % 1000) + " " + v[i] + " " + res : res;
    }
    while (res.back() == ' ')
        res.pop_back();
    return res.empty() ? "Zero" : res;
}

string to_lower_case(string str)
{
    string ret;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ret.push_back(str[i] + 'a' - 'A');
        } else {
            ret.push_back(str[i]);
        }
    }
    return ret;
}

int rotated_digits(int N)
{
    int res = 0;
    vector<int> dp(N + 1);   
    for (int i = 0; i <= N; ++i) {
        if (i < 10) {
            if (i == 0 || i == 1 || i == 8)
                dp[i] = 1;
            else if (i == 2 || i == 5 || i == 6 || i == 9) {
                dp[i] = 2; ++res;
            }
        } else {
            int a = dp[i / 10], b = dp[i % 10];
            if (a == 1 && b == 1)
                dp[i] = 1;
            else if (a >= 1 && b >= 1) {
                dp[i] = 2; ++res;
            }
        }
    }
    return res;
}

string optimal_division(vector<int>& nums)
{
    string res = "";
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            res += "/";
        if (i == 1 && n > 2)
            res += "(";
        res += to_string(nums[i]);
        if (i == n - 1 && n > 2)
            res += ")";
    }
    return res;
}

bool is_number(string s)
{
    bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign))
                return false;
        } else if (s[i] == '+' || s[i] == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ')
                return false;
            sign = true;
        } else if (s[i] >= '0' && s[i] <= '9') {
            num = true;
            numAfterE = true;
        } else if (s[i] == '.') {
            if (dot || exp)
                return false;
            dot = true;
        } else if (s[i] == 'e') {
            if (exp || !num)
                return false;
            exp = true;
            numAfterE = false;
        } else return false;
    }
    return num && numAfterE;
}

bool repeated_substring_pattern(string str)
{
    int i = 1, j = 0, n = str.size();
    vector<int> dp(n + 1, 0);
    while (i < n) {
        if (str[i] == str[j])
            dp[++i] = ++j;
        else if (j == 0)
            ++i;
        else
            j = dp[j];
    }
    return dp[n] && (dp[n] % (n - dp[n]) == 0);
}

bool buddy_strings(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int cnt = 0;
    string da, db;
    for (int i=0; i<a.size(); ++i) {
        if (a[i] == b[i]) {
            continue;
        } else {
            cnt += 1;
            if (cnt > 2)
                return false;
            da.push_back(a[i]);
            db.push_back(b[i]);
        }
    }
    if (cnt == 2) {
        if (da[0] == db[1] && da[1] == db[0])
            return true;
    }     
    if (cnt == 0) {
        for (int i = 1; i<a.size(); ++i){
            if (a[i] == a[0])
                return true;
        }
    }
    return false;            
}

string reorganize_string(string S)
{
    int n = S.size(), idx = 1;
    vector<int> cnt(26, 0);
    for (char c : S) cnt[c - 'a'] += 100;
    for (int i = 0; i < 26; ++i) cnt[i] += i;
    sort(cnt.begin(), cnt.end());
    for (int num : cnt) {
        int t = num / 100;
        char ch = 'a' + (num % 100);
        if (t > (n + 1) / 2) return "";
        for (int i = 0; i < t; ++i) {
            if (idx >= n) idx = 0;
            S[idx] = ch;
            idx += 2;
        }
    }
    return S;
}

vector<string> letter_combinations(string digits)
{
    vector<string> res;
    if (digits.empty())
        return res;
    string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); ++i) {
        int n = res.size();
        string str = dict[digits[i] - '2'];
        for (int j = 0; j < n; ++j) {
            string tmp = res.front();
            res.erase(res.begin());
            for (int k = 0; k < str.size(); ++k) {
                res.push_back(tmp + str[k]);
            }
        }
    }
    return res;
}

string simplify_path(string path)
{
    vector<string> v;
    char *cstr = new char[path.length() + 1];
    strcpy(cstr, path.c_str());
    char *pch = strtok(cstr, "/");
    while (pch != NULL) {
        string p = string(pch);
        if (p == "..") {
            if (!v.empty())
                v.pop_back();
        } else if (p != ".") {
            v.push_back(p);
        }
        pch = strtok(NULL, "/");
    }
    if (v.empty())
        return "/";
    string res;
    for (int i = 0; i < v.size(); ++i) {
        res += '/' + v[i];
    }
    return res;
}

int my_atoi(string str)
{
    if (str.empty())
        return 0;
    int sign = 1, base = 0, i = 0, n = str.size();
    while (i < n && str[i] == ' ') ++i;
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '+') ? 1 : -1;
    }
    while (i < n && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;   
}

int length_of_longest_substring(string s)
{
    int m[256] = {0}, res = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            res = max(res, i - left + 1);
        } else {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }
    return res;
}

int find_min_difference(vector<string>& timePoints)
{
    int res = INT_MAX, n = timePoints.size(), diff = 0;
    sort(timePoints.begin(), timePoints.end());
    for (int i = 0; i < n; ++i) {
        string t1 = timePoints[i], t2 = timePoints[(i + 1) % n];
        int h1 = (t1[0] - '0') * 10 + t1[1] - '0';
        int m1 = (t1[3] - '0') * 10 + t1[4] - '0';
        int h2 = (t2[0] - '0') * 10 + t2[1] - '0';
        int m2 = (t2[3] - '0') * 10 + t2[4] - '0';
        diff = (h2 - h1) * 60 + (m2 - m1);
        if (i == n - 1)
            diff += 24 * 60;
        res = min(res, diff);
    }
    return res;
}
