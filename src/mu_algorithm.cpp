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
#include <string>

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

char* mu_is_power_of_two()
{
    mu_assert(true == is_power_of_two(1), "");
    mu_assert(true == is_power_of_two(16), "");
    mu_assert(false == is_power_of_two(100), "");
    
    return 0;
}

char* mu_is_power_of_four()
{
    mu_assert(true == is_power_of_four(4), "");
    mu_assert(true == is_power_of_four(1), "");
    mu_assert(true == is_power_of_four(16), "");
    mu_assert(false == is_power_of_four(13), "");
    mu_assert(false == is_power_of_four(8), "");
    
    return 0;
}

char* mu_is_power_of_three()
{
    mu_assert(true == is_power_of_three(1), "");
    mu_assert(true == is_power_of_three(27), "");
    mu_assert(true == is_power_of_three(81), "");
    mu_assert(false == is_power_of_three(15), "");
    mu_assert(false == is_power_of_three(100), "");
    
    return 0;
}

char* mu_count_one()
{
    mu_assert(1 == count_one(8), "");
    mu_assert(1 == count_one2(8), "");
    mu_assert(4 == count_one(15), "");
    mu_assert(4 == count_one2(15), "");
    mu_assert(1 == count_one(16), "");
    mu_assert(1 == count_one2(16), "");
    
    return 0;
}

char* mu_count_bits()
{
    vector<int> ret = count_bits(5);
    mu_assert(6 == ret.size(), "");
    mu_assert(0 == ret[0], "");
    mu_assert(1 == ret[1], "");
    mu_assert(1 == ret[2], "");
    mu_assert(2 == ret[3], "");
    mu_assert(1 == ret[4], "");
    mu_assert(2 == ret[5], "");

    return 0;
}

char* mu_to_hex()
{
    mu_assert("1a" == to_hex(26), "");

    return 0;
}

char* mu_hamming_distance()
{
    mu_assert(2 == hamming_distance(2, 4), "");

    return 0;
}

char* mu_integer_replacement()
{
    mu_assert(3 == integer_replacement(8), "");
    mu_assert(4 == integer_replacement(7), "");

    return 0;
}

char* mu_find_the_difference()
{
    mu_assert('e' == find_the_difference("abcd", "abcde"), "");
    mu_assert('a' == find_the_difference("a", "aa"), "");
    mu_assert('a' == find_the_difference("abcde", "abcade"), "");

    return 0;
}

char* mu_total_hamming_distance()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(12);
    nums.push_back(2);
    mu_assert(6 == total_hamming_distance(nums), "");

    return 0;
}

char* mu_missing_number()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    mu_assert(2 == missing_number(nums), "");
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(9);
    nums.push_back(7);
    nums.push_back(6);
    mu_assert(8 == missing_number(nums), "");

    return 0;
}

char* algorithm_suites()
{
    mu_run_test(mu_single_number);
    mu_run_test(mu_single_number2);
    mu_run_test(mu_is_power_of_two);
    mu_run_test(mu_is_power_of_four);
    mu_run_test(mu_is_power_of_three);
    mu_run_test(mu_count_one);
    mu_run_test(mu_count_bits);
    mu_run_test(mu_to_hex);
    mu_run_test(mu_hamming_distance);
    mu_run_test(mu_integer_replacement);
    mu_run_test(mu_find_the_difference);
    mu_run_test(mu_total_hamming_distance);
    mu_run_test(mu_missing_number);

    return 0;
}
