// mu_greedy.cpp --- 
// Filename: mu_greedy.cpp
// Created: Sat Sep 22 22:04:18 2018 (+0800)
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
#include "utl_greedy.h"

using namespace std;

char* mu_is_match()
{
    char s[] = "adceb";
    char p[] = "*a*b";
    mu_assert(true == is_match(s, p), "");
    
    return 0;
}

char* mu_monotone_increasing_digits()
{
    mu_assert(1234 == monotone_increasing_digits(1234), "");
    mu_assert(299 == monotone_increasing_digits(332), "");
    
    return 0;
}

char* mu_can_jump()
{
    int nums[] = {2, 3, 1, 1, 4};
    mu_assert(true == can_jump(nums, 5), "");
    
    return 0;
}

char* mu_jump()
{
    int nums[] = {2, 3, 1, 1, 4};
    mu_assert(2 == jump(nums, 5), "");
    
    return 0;
}

char* greedy_suites()
{
    mu_run_test(mu_is_match);
    mu_run_test(mu_monotone_increasing_digits);
    mu_run_test(mu_can_jump);
    mu_run_test(mu_jump);
    
    return 0;
}
