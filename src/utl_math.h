/* utl_math.h --- 
 * Filename: utl_math.h
 * Created: Tue Sep 11 20:36:40 2018 (+0800)
 */

/* Copyright Hamlet zheng.
 * 
 * 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
 * copyright部分和本使用声明部分，除非显示声明，copyright的持有者
 * 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef UTL_MATH_H_
#define UTL_MATH_H_

#include <iostream>
#include <math.h>

#define EQUAL_F(a, b) (fabs((a) - (b)) < 1e-6)

// leetcode 7
int reverse_int(int x);
// leetcode 66
std::vector<int> plus_one(std::vector<int>& digits);
// leetcode 69
int my_sqrt(int x);
// leetcode 50
double my_pow(double x, int n);
// leetcode 400
int find_nth_digit(int n);
// leetcode 441
int arrange_coins(int n);
// leetcode 507
bool check_perfect_number(int num);
// leetcode 628
int maximum_product(std::vector<int>& nums);
// leetcode 258
int add_digits(int num);
// leetcode 453
int min_moves(std::vector<int>& nums);
// leetcode 462
int min_moves2(std::vector<int>& nums);
// leetcode 423
std::string original_digits(std::string s);
// leetcode 396
int max_rotate_function(std::vector<int>& A);
// leetcode 372
int super_pow(int a, std::vector<int>& b);
// leetcode 728
std::vector<int> self_dividing_numbers(int left, int right);
// leetcode 202
bool is_happy_number(int n);
// leetcode 263
bool is_ugly_number(int num);
// leetcode 264
int nth_ugly_number(int n);
// leetcode 633
bool judge_square_sum(int c);
// leetcode 367
bool is_perfect_square(int num);
// leetcode 645
std::vector<int> find_error_nums(std::vector<int>& nums);
// leetcode 537
std::string complex_number_multiply(std::string a, std::string b);
// leetcode 168
std::string convert_to_title(int n);
// leetcode 171
int title_to_number(std::string s);
// leetcode 29
int divide(int dividend, int divisor);

#endif
