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
