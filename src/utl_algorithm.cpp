// utl_algorithm.cpp --- 
// Filename: utl_algorithm.cpp
// Created: Thu Sep  6 21:53:54 2018 (+0800)
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

#include "utl_algorithm.h"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int single_number(std::vector<int>& nums)
{
    int num = 0;
    for (int i = 0; i < nums.size(); ++i) {
        num ^= nums[i];
    }
    return num;
}

int single_number2(vector<int>& nums)
{
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    return res;
}

bool is_power_of_two(int n)
{
    return (n > 0) && ((n & (n-1)) == 0);
}

bool is_power_of_four(int num)
{
    return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
}

bool is_power_of_three(int n)
{
    // power(3, 19) == 1162261467
    return (n > 0 && 1162261467 % n == 0);
}

vector<int> count_bits(int num)
{
    vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

int count_one(int num)
{
    int ret = 0;
    while (num) {
        if (num & 1)
            ret++;
        num >>= 1;
    }
    return ret;
}

int count_one2(int num)
{
    int ret = 0;
    while (num) {
        num = num & (num - 1);
        ret++;
    }
    return ret;
}

string to_hex(int num)
{
    string res = "", str = "0123456789abcdef";
    int cnt = 0;
    while (num != 0 && cnt++ < 8) {
        res = str[(num & 0xf)] + res;
        num >>= 4;
    }
    return res.empty() ? "0" : res;
}

int hamming_distance(int x, int y)
{
    int tmp = x ^ y;
    int ret = 0;
    while (tmp) {
        tmp = tmp & (tmp - 1);
        ret++;
    }
    return ret;
}

int integer_replacement(int n)
{
    long long t = n;
    int cnt = 0;
    while (t > 1) {
        ++cnt;
        if (t & 1) {
            if ((t & 2) && (t != 3))
                ++t;
            else
                --t;
        } else {
            t >>= 1;
        }
    }
    return cnt;
}

char find_the_difference(string s, string t)
{
    char res = 0;
    for (char c : s)
        res ^= c;
    for (char c : t)
        res ^= c;
    return res;
}

int total_hamming_distance(vector<int>& nums)
{
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int cnt = 0;
        for (int num : nums) {
            if (num & (1 << i))
                ++cnt;
        }
        res += cnt * (n - cnt);
    }
    return res;
}

int missing_number(vector<int>& nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        res ^= (i + 1) ^ nums[i];
    }
    return res;
}

int majority_element(vector<int>& nums)
{
    int res = 0, cnt = 0;
    for (int num : nums) {
        if (cnt == 0) {
            res = num;
            ++cnt;
        } else {
            (num == res) ? ++cnt : --cnt;
        }
    }
    return res;
}

int majority_element2(std::vector<int>& nums)
{
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int ones = 0, zeros = 0;
        for (int num : nums) {
            if (ones > n / 2 || zeros > n / 2)
                break;
            if ((num & (1 << i)) != 0)
                ++ones;
            else
                ++zeros;
        }
        if (ones > zeros)
            res |= (1 << i);
    }
    return res;
}

vector<string> letter_case_permutation(string S)
{
    vector<string> res;
    int cnt = 0;
    for (char c : S) {
        if (c > '9')
            ++cnt;
    }
    for (int i = 0; i < (1 << cnt); ++i) {
        int j = 0;
        string word = "";
        for (char c : S) {
            if (c > '9') {
                if (((i >> j++) & 1) == 1) {
                    word.push_back(tolower(c));
                } else {
                    word.push_back(toupper(c));
                }
            } else {
                word.push_back(c);
            }
        }
        res.push_back(word);
    }
    return res;
}

bool has_alternating_bits(int n)
{
    return ((n + (n >> 1) + 1) & (n + (n >> 1))) == 0;
}

int find_complement(int num)
{
    bool start = false;
    for (int i = 31; i >= 0; --i) {
        if (num & (1 << i)) 
            start = true;
        if (start) 
            num ^= (1 << i);
    }
    return num;
}

int range_bitwise_and(int m, int n)
{
    int i = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    return (m << i);   
}

int get_sum(int a, int b)
{
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return get_sum(sum, carry);
}

uint32_t reverse_bits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n & 1) == 1) {
            res = (res << 1) + 1;
        } else {
            res = res << 1;
        }
        n = n >> 1;
    }
    return res;
}

int max_product(vector<string>& words)
{
    int res = 0;
    vector<int> mask(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
        for (char c : words[i]) {
            mask[i] |= 1 << (c - 'a');
        }
        for (int j = 0; j < i; ++j) {
            if (!(mask[i] & mask[j])) {
                res = max(res, int(words[i].size() * words[j].size()));
            }
        }
    }
    return res;   
}

int find_maximum_xor(vector<int>& nums)
{
    int res = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num & mask);
        }
        int t = res | (1 << i);
        for (int prefix : s) {
            if (s.count(t ^ prefix)) {
                res = t;
                break;
            }
        }
    }
    return res;
}
