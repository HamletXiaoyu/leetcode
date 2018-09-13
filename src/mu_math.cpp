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

char* mu_my_sqrt()
{
    mu_assert(2 == my_sqrt(8), "");
    mu_assert(2 == my_sqrt(4), "");
    mu_assert(3 == my_sqrt(15), "");
    mu_assert(4 == my_sqrt(20), "");
    
    return 0;
}

char* mu_my_pow()
{
    mu_assert(EQUAL_F(4, my_pow(2, 2)), "");
    mu_assert(EQUAL_F(9.26100, my_pow(2.1, 3)), "");
    mu_assert(EQUAL_F(0.25, my_pow(2, -2)), "");
              
    return 0;
}

char* mu_find_nth_digit()
{
    mu_assert(3 == find_nth_digit(3), "");
    mu_assert(0 == find_nth_digit(11), "");
    
    return 0;
}

char* mu_arrange_coins()
{
    mu_assert(2 == arrange_coins(5), "");
    mu_assert(3 == arrange_coins(8), "");
    
    return 0;
}

char* mu_check_perfect_number()
{
    mu_assert(true == check_perfect_number(6), "");
    mu_assert(true == check_perfect_number(28), "");
    mu_assert(false == check_perfect_number(36), "");
    
    return 0;
}

char* mu_maximum_product()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    mu_assert(6 == maximum_product(num), "");
    num.push_back(-1);
    num.push_back(-2);
    num.push_back(-3);
    mu_assert(18 == maximum_product(num), "");
    
    return 0;
}

char* mu_add_digits()
{
    mu_assert(2 == add_digits(38), "");
    mu_assert(2 == add_digits(20), "");
    mu_assert(2 == add_digits(11), "");
    
    return 0;
}

char* mu_min_moves()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    mu_assert(3 == min_moves(nums), "");
    mu_assert(2 == min_moves2(nums), "");
    
    return 0;
}

char* mu_original_digits()
{
    mu_assert("45" == original_digits("fviefuro"), "");
    mu_assert("012" == original_digits("owoztneoer"), "");
    
    return 0;
}

char* mu_super_pow()
{
    vector<int> b;
    b.push_back(3);
    mu_assert(8 == super_pow(2, b), "");
    
    return 0;
}

char* math_suites()
{
    mu_run_test(mu_reverse_int);
    mu_run_test(mu_plus_one);
    mu_run_test(mu_my_sqrt);
    mu_run_test(mu_my_pow);
    mu_run_test(mu_find_nth_digit);
    mu_run_test(mu_arrange_coins);
    mu_run_test(mu_check_perfect_number);
    mu_run_test(mu_maximum_product);
    mu_run_test(mu_add_digits);
    mu_run_test(mu_min_moves);
    mu_run_test(mu_original_digits);
    mu_run_test(mu_super_pow);
    
    return 0;
}
