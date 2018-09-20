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

char* mu_self_dividing_numbers()
{
    vector<int> ret;
    ret = self_dividing_numbers(1, 22);
    int exp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    mu_assert(13 == ret.size(), "");
    for (int i = 0; i<13; ++i) {
        mu_assert(ret[i] == exp[i], "");
    }
    
    return 0;
}

char* mu_is_happy_number()
{
    mu_assert(true == is_happy_number(19), "");
    mu_assert(false == is_happy_number(11), "");
    
    return 0;
}

char* mu_is_ugly_number()
{
    mu_assert(true == is_ugly_number(6), "");
    mu_assert(true == is_ugly_number(8), "");
    mu_assert(true == is_ugly_number(10), "");
    mu_assert(false == is_ugly_number(14), "");
    mu_assert(false == is_ugly_number(35), "");
    
    return 0;
}

char* mu_nth_ugly_number()
{
    mu_assert(12 == nth_ugly_number(10), "");
    
    return 0;
}

char* mu_judge_square_sum()
{
    mu_assert(true == judge_square_sum(5), "");
    mu_assert(false == judge_square_sum(3), "");
    
    return 0;
}

char* mu_is_perfect_square()
{
    mu_assert(true == is_perfect_square(49), "");
    mu_assert(true == is_perfect_square(64), "");
    mu_assert(true == is_perfect_square(81), "");
    mu_assert(false == is_perfect_square(80), "");
    mu_assert(false == is_perfect_square(180), "");
    mu_assert(false == is_perfect_square(101), "");
    
    return 0;
}

char* mu_find_error_nums()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    vector<int> ret = find_error_nums(nums);
    mu_assert(2 == ret.size(), "");
    mu_assert(2 == ret[0], "");
    mu_assert(3 == ret[1], "");
    
    return 0;
}

char* mu_complex_number_multiply()
{
    mu_assert("0+2i" == complex_number_multiply("1+1i", "1+1i"), "");
    
    return 0;
}

char* mu_convert_to_title()
{
    mu_assert("B" == convert_to_title(2), "");
    mu_assert("AB" == convert_to_title(28), "");
    mu_assert("ZY" == convert_to_title(701), "");
    
    return 0;
}

char* mu_title_to_number()
{
    mu_assert(2 == title_to_number("B"), "");
    mu_assert(28 == title_to_number("AB"), "");
    mu_assert(701 == title_to_number("ZY"), "");
    
    return 0;
}

char* mu_divide()
{
    mu_assert(3 == divide(10, 3), "");
    mu_assert(5 == divide(10, 2), "");
    mu_assert(-2 == divide(7, -3), "");
    
    return 0;
}

char* mu_get_permutation()
{
    mu_assert("213" == get_permutation(3, 3), "");
    mu_assert("2314" == get_permutation(4, 9), "");
    
    return 0;
}

char* mu_fraction_addition()
{
    mu_assert("1/3" == fraction_addition("-1/2+1/2+1/3"), "");
    mu_assert("-1/6" == fraction_addition("1/3-1/2"), "");
    
    return 0;
}

char* mu_bulb_switch()
{
    mu_assert(1 == bulb_switch(3), "");
    mu_assert(2 == bulb_switch(5), "");
    
    return 0;
}

char* mu_flip_lights()
{
    mu_assert(2 == flip_lights(1, 1), "");
    mu_assert(3 == flip_lights(2, 1), "");
    mu_assert(4 == flip_lights(3, 1), "");
    
    return 0;
}

char* mu_count_digit_one()
{
    mu_assert(6 == count_digit_one(13), "");
    
    return 0;
}

char* mu_maximum_swap()
{
    mu_assert(7236 == maximum_swap(2736), "");
    mu_assert(9916 == maximum_swap(1996), "");
    
    return 0;
}

char* mu_count_numbers_with_unique_digits()
{
    mu_assert(91 == count_numbers_with_unique_digits(2), "");
    
    return 0;
}

char* mu_fraction_to_decimal()
{
    mu_assert("0.5" == fraction_to_decimal(1, 2), "");
    mu_assert("2" == fraction_to_decimal(2, 1), "");
    mu_assert("0.(6)" == fraction_to_decimal(2, 3), "");
    
    return 0;
}

char* mu_solve_equation()
{
    mu_assert("x=2" == solve_equation("x+5-3+x=6+x-2"), "");
    mu_assert("x=0" == solve_equation("2x=x"), "");
    mu_assert("Infinite solutions" == solve_equation("x=x"), "");
    mu_assert("x=-1" == solve_equation("2x+3x-6x=x+2"), "");
    mu_assert("No solution" == solve_equation("x=x+2"), "");
    
    return 0;
}

char* mu_num_squares()
{
    mu_assert(3 == num_squares(12), "");
    mu_assert(2 == num_squares(13), "");
    
    return 0;
}

char* mu_can_measure_water()
{
    mu_assert(true == can_measure_water(3, 5, 4), "");
    
    return 0;
}

char* mu_integer_break()
{
    mu_assert(36 == integer_break(10), "");
    mu_assert(1 == integer_break(2), "");
    
    return 0;
}

char* mu_calculate()
{
    mu_assert(23 == calculate("(1+(4+5+2)-3)+(6+8)"), "");
    mu_assert(23 == calculate("1 +2 -1+20 + 1"), "");
    
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
    mu_run_test(mu_self_dividing_numbers);
    mu_run_test(mu_is_happy_number);
    mu_run_test(mu_is_ugly_number);
    mu_run_test(mu_nth_ugly_number);
    mu_run_test(mu_judge_square_sum);
    mu_run_test(mu_is_perfect_square);
    mu_run_test(mu_find_error_nums);
    mu_run_test(mu_complex_number_multiply);
    mu_run_test(mu_convert_to_title);
    mu_run_test(mu_title_to_number);
    mu_run_test(mu_divide);
    mu_run_test(mu_get_permutation);
    mu_run_test(mu_fraction_addition);
    mu_run_test(mu_bulb_switch);
    mu_run_test(mu_flip_lights);
    mu_run_test(mu_count_digit_one);
    mu_run_test(mu_maximum_swap);
    mu_run_test(mu_count_numbers_with_unique_digits);
    mu_run_test(mu_fraction_to_decimal);
    mu_run_test(mu_solve_equation);
    mu_run_test(mu_num_squares);
    mu_run_test(mu_can_measure_water);
    mu_run_test(mu_integer_break);
    mu_run_test(mu_calculate);
    
    return 0;
}
