// mu_math.cpp --- 
// Filename: mu_math.cpp
// Created: Tue Sep 11 20:37:22 2018 (+0800)
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

#include "minunit.h"
#include "mu_suites.h"
#include "utl_math.h"
#include <vector>

using namespace std;

char* mu_reverse_int()
{
    mu_assert(123 == reverse_int(321), "");
    mu_assert(-123 == reverse_int(-321), "");
    mu_assert(0 == reverse_int(1000000009), "");
    
    return 0;
}

char* mu_plus_one()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    vector<int> ret;
    ret = plus_one(num);
    mu_assert(3 == ret.size(), "");
    mu_assert(1 == ret[0], "");
    mu_assert(2 == ret[1], "");
    mu_assert(4 == ret[2], "");

    num.push_back(9);
    ret = plus_one(num);
    mu_assert(4 == ret.size(), "");
    mu_assert(1 == ret[0], "");
    mu_assert(2 == ret[1], "");
    mu_assert(4 == ret[2], "");
    mu_assert(0 == ret[3], "");
    
    return 0;
}

char* math_suites()
{
    mu_run_test(mu_reverse_int);
    mu_run_test(mu_plus_one);
    
    return 0;
}
