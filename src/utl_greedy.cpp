// utl_greedy.cpp --- 
// Filename: utl_greedy.cpp
// Created: Sat Sep 22 22:04:02 2018 (+0800)
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

#include "utl_greedy.h"
#include <string>
#include <vector>

using namespace std;

bool is_match(char* s, char* p)
{
    char *scur = s, *pcur = p, *sstar = NULL, *pstar = NULL;
    while (*scur) {
        if (*scur == *pcur || *pcur == '?') {
            ++scur;
            ++pcur;
        } else if (*pcur == '*') {
            pstar = pcur++;
            sstar = scur;
        } else if (pstar) {
            pcur = pstar + 1;
            scur = ++sstar;
        } else {
            return false;
        }
    } 
    while (*pcur == '*')
        ++pcur;
    return !*pcur;
}

int monotone_increasing_digits(int N)
{
    string str = to_string(N);
    int n = str.size(), j = n;
    for (int i = n - 1; i > 0; --i) {
        if (str[i] >= str[i - 1])
            continue;
        --str[i - 1];
        j = i;
    }        
    for (int i = j; i < n; ++i) {
        str[i] = '9';
    }
    return stoi(str);
}

bool can_jump(int* nums, int numsSize)
{
    int reach = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i > reach || reach >= numsSize - 1) 
            break;
        reach = reach > i + nums[i] ? reach : i + nums[i];
    }
    return reach >= numsSize - 1;
}

int jump(int* nums, int n)
{
    int res = 0, i = 0, cur = 0;
    while (cur < n - 1) {
        ++res;
        int pre = cur;
        for (; i <= pre; ++i) {
            cur = max(cur, i + nums[i]);
        }
    }
    return res;
}

int max_profit(int* prices, int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            res += prices[i + 1] - prices[i];
        }
    }
    return res;
}

int max_profit1(int* prices, int n)
{
    int res = 0, buy = INT_MAX;
    for (int i = 0; i < n; ++i) {
        buy = buy > prices[i] ? prices[i] : buy;
        res = res > prices[i] - buy ? res : prices[i] - buy;
    }
    return res;
}

int max_profit_with_fee(int* prices, int n, int fee)
{
    int sold = 0, hold = -prices[0];
    for (int i = 0; i < n; ++i) {
        int t = sold, price = prices[i];
        sold = sold > hold + price - fee ? sold : hold + price - fee;
        hold = hold > t - price ? hold : t - price;
    }
    return sold;
}

int can_complete_circuit(int* gas, int gas_size, int* cost, int cost_size)
{
    int total = 0, sum = 0, start = 0;
    for (int i = 0; i < gas_size; ++i) {
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if (sum < 0) {
            start = i + 1;
            sum = 0;
        }
    }
    return (total < 0) ? -1 : start;
}

void quick_sort(int a[], int low, int high)
{
    int left = low, right = high, key = a[low];
    if (left >= right)
        return;
    while (left != right) {
        while (left != right && a[right] > key)
            right--;
        a[left] = a[right];
        while (left != right && a[left] < key)
            left++;
        a[right] = a[left];
    }
    a[left] = key;
    quick_sort(a, low, left-1);
    quick_sort(a, left+1, high);
}

void insert_sort(int a[], int n)
{
    int i, j;
    int pre, cur;
    for (i = 1; i < n; ++i) {
        pre = i - 1;
        cur = a[i];
        while (pre >= 0 && a[pre] > cur) {
            a[pre+1] = a[pre];
            pre--;
        }
        a[pre + 1] = cur;
    }
}

int find_content_children(int* g, int g_size, int* s, int s_size)
{
    insert_sort(s, s_size);
    int* flag = (int*)malloc(g_size * sizeof(int));
    memset(flag, 0, g_size * sizeof(int));
    int ret=0;
    for (int i = 0; i < s_size; ++i) {
        int target = -1;
        for(int j = 0; j < g_size; ++j) {
            if (flag[j] == 0 && s[i] >= g[j]) {
                if (target == -1)
                    target = j;
                else {
                    if (flag[target] < flag[j])
                        target = j;
                }
            }
        }
        if (target != -1) {
            flag[target] = 1;
            ret++;
        }
    }
    free(flag);
    return ret;
}

int find_content_children(vector<int>& g, vector<int>& s)
{
    int j = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() && j < g.size(); ++i) {
        if (s[i] >= g[j]) ++j;
    }
    return j;
}

int candy(int* ratings, int n)
{
    int* nums = (int*)malloc(n * sizeof(int));
    int ret = 0, i = 0;
    for (i = 0; i < n; ++i)
        nums[i] = 1;
    for (i = 0; i < n - 1; ++i) {
        if (ratings[i+1] > ratings[i])
            nums[i+1] = nums[i] + 1;
    }
    for (i = n - 1; i > 0; --i) {
        if (ratings[i-1] > ratings[i])
            nums[i-1] = nums[i] + 1 > nums[i-1] ? nums[i]+1 : nums[i-1];
    }
    for (i = 0; i < n; ++i) {
        ret += nums[i];
    }
    free(nums);
    return ret;
}

bool is_subsequence(string s, string t)
{
    if (s.empty())
        return true;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ++i; ++j;
        } else {
            ++j;
        }
    }
    return i == s.size();
}

string remove_k_digits(string num, int k)
{
    string res = "";
    int n = num.size(), keep = n - k;
    for (char c : num) {
        while (k && res.size() && res.back() > c) {
            res.pop_back();
            --k;
        }
        res.push_back(c);
    }
    res.resize(keep);
    while (!res.empty() && res[0] == '0')
        res.erase(res.begin());
    return res.empty() ? "0" : res;
}

int min_swaps_couples(int* row, int n)
{
    int res = 0;
    for (int i = 0; i < n; i += 2) {
        if (row[i + 1] == (row[i] ^ 1))
            continue;
        ++res;
        for (int j = i + 1; j < n; ++j) {
            if (row[j] == (row[i] ^ 1)) {
                row[j] = row[i + 1];
                row[i + 1] = row[i] ^ 1;
                break;
            }
        }
    }
    return res;
}
