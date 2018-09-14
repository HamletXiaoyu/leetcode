// utl_math.cpp --- 
// Filename: utl_math.cpp
// Created: Tue Sep 11 20:36:51 2018 (+0800)
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

#include "utl_math.h"
#include <vector>
#include <math.h>

using namespace std;

int reverse_int(int x)
{
    int res = 0;
    while (x != 0) {
        if (abs(res) > INT_MAX / 10) 
            return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;   
}

vector<int> plus_one(vector<int>& digits)
{
    int n = digits.size();
    vector<int> ret;
    int carry = 0;
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1) {
            ret.push_back((digits[i] + 1) % 10);
            carry = (digits[i] + 1) / 10;
        } else {
            ret.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
    }
    if (carry != 0)
        ret.push_back(1);
    reverse(ret.begin(), ret.end());
    return ret;
}

int my_sqrt(int x)
{
    if (x == 0) 
        return 0;
    double res = 1, pre = 0;
    while (fabs(res - pre) > 1e-6) {
        pre = res;
        res = (res + x / res) / 2;
    }
    return int(res);   
}

double my_pow(double x, int n)
{
    double res = 1.0;
    for (int i = n; i != 0; i /= 2) {
        if (i % 2 != 0)
            res *= x;
        x *= x;
    }
    return n < 0 ? 1 / res : res;   
}

int find_nth_digit(int n)
{
    long long len = 1, cnt = 9, start = 1;
    while (n > len * cnt) {
        n -= len * cnt;
        ++len;
        cnt *= 10;
        start *= 10;
    }
    start += (n - 1) / len;
    string t = to_string(start);
    return t[(n - 1) % len] - '0';
}

int arrange_coins(int n)
{
    if (n <= 1)
        return n;
    long low = 1, high = n;
    while (low < high) {
        long mid = low + (high - low) / 2;
        if (mid * (mid + 1) / 2 <= n)
            low = mid + 1;
        else
            high = mid;
    }
    return low - 1;
}

bool check_perfect_number(int num)
{
    if (num == 1)
        return false;
    int sum = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            sum += (i + num / i);
        if (i * i == num)
            sum -= i;
        if (sum > num)
            return false;
    }
    return sum == num;
}

int maximum_product(vector<int>& nums)
{
    int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for (int num : nums) {
        if (num > mx1) {
            mx3 = mx2; mx2 = mx1; mx1 = num;
        } else if (num > mx2) {
            mx3 = mx2; mx2 = num;
        } else if (num > mx3) {
            mx3 = num;
        }
        if (num < mn1) {
            mn2 = mn1; mn1 = num;
        } else if (num < mn2) {
            mn2 = num;
        }
    }
    return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
}

int add_digits(int num)
{
    return (num - 1) % 9 + 1;
}

int min_moves(vector<int>& nums)
{
    int mn = INT_MAX, res = 0;
    for (int num : nums)
        mn = min(mn, num);
    for (int num : nums)
        res += num - mn;
    return res;
}

int min_moves2(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int res = 0, mid = nums[nums.size() / 2];
    for (int num : nums) {
        res += abs(num - mid);
    }
    return res;
}

string original_digits(string s)
{
    string res = "";
    vector<int> counts(128, 0), nums(10, 0);
    for (char c : s)
        ++counts[c];
    nums[0] = counts['z'];
    nums[2] = counts['w'];
    nums[4] = counts['u'];
    nums[6] = counts['x'];
    nums[8] = counts['g'];
    nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
    nums[3] = counts['h'] - nums[8];
    nums[5] = counts['f'] - nums[4];
    nums[7] = counts['s'] - nums[6];
    nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i]; ++j) {
            res += (i + '0');
        }
    }
    return res;
}

int max_rotate_function(vector<int>& A)
{
    int t = 0, sum = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        sum += A[i];
        t += i * A[i];
    }
    int res = t;
    for (int i = 1; i < n; ++i) {
        t = t + sum - n * A[n - i];
        res = max(res, t);
    }
    return res;
}

int super_pow_helper(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x % 1337;
    return super_pow_helper(x % 1337, n / 2) * super_pow_helper(x % 1337, n - n / 2) % 1337;
}

int super_pow(int a, vector<int>& b)
{
    long long res = 1;
    for (int i = 0; i < b.size(); ++i) {
        res = (super_pow_helper(res, 10) * super_pow_helper(a, b[i])) % 1337;
    }
    return res;
}

vector<int> self_dividing_numbers(int left, int right)
{
    vector<int> res;
    for (int i = left, n = 0; i <= right; ++i) {
        for (n = i; n > 0; n /= 10) {
            if (n % 10 == 0 || i % (n % 10) != 0) 
                break;
        }
        if (n == 0) 
            res.push_back(i);
    }
    return res;
}

bool is_happy_number(int n)
{
    while (n != 1 && n != 4) {
        int t = 0;
        while (n) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }
        n = t;
    }
    return n == 1;
}
