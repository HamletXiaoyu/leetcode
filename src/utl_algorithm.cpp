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
