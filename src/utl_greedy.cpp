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
