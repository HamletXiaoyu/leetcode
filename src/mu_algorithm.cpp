// mu_algorithm.cpp --- 
// Filename: mu_algorithm.cpp
// Created: Thu Sep  6 21:55:16 2018 (+0800)
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
#include "utl_algorithm.h"
#include <vector>

using namespace std;

char* mu_single_number()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    mu_assert(2 == single_number(nums), "");
    nums.push_back(2);
    nums.push_back(3);
    mu_assert(3 == single_number(nums), "");

    return 0;
}

char* mu_single_number2()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    mu_assert(2 == single_number2(nums), "");
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    mu_assert(3 == single_number2(nums), "");

    return 0;
}

char* algorithm_suites()
{
    mu_run_test(mu_single_number);
    mu_run_test(mu_single_number2);

    return 0;
}
