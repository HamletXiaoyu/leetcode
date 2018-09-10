/* utl_algorithm.h --- 
 * Filename: utl_algorithm.h
 * Created: Thu Sep  6 21:53:44 2018 (+0800)
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

#ifndef UTL_ALGORITHM_H_
#define UTL_ALGORITHM_H_

#include <iostream>

// leetcode 136
int single_number(std::vector<int>& nums);
// leetcode 137
int single_number2(std::vector<int>& nums);
// leetcode 231
bool is_power_of_two(int n);
// leetcode 342
bool is_power_of_four(int num);
// leetcode 326
bool is_power_of_three(int n);
// leetcode 338
std::vector<int> count_bits(int num);
// leetcode 191
int count_one(int num); //hamming weight
int count_one2(int num);
// leetcode 405
std::string to_hex(int num);
// leetcode 461
int hamming_distance(int x, int y);
// leetcode 397
int integer_replacement(int n);
// leetcode 389
char find_the_difference(std::string s, std::string t);
// leetcode 477
int total_hamming_distance(std::vector<int>& nums);
// leetcode 268
int missing_number(std::vector<int>& nums);
// leetcode 169
int majority_element(std::vector<int>& nums); // moore voting
int majority_element2(std::vector<int>& nums); // bit op
// leetcode 784
std::vector<std::string> letter_case_permutation(std::string S);
// leetcode 693
bool has_alternating_bits(int n);
// leetcode 476
int find_complement(int num);
// leetcode 206
int range_bitwise_and(int m, int n);
// leetcode 371
int get_sum(int a, int b);
// leetcode 190
uint32_t reverse_bits(uint32_t n);
// leetcode 318
int max_product(std::vector<std::string>& words);

#endif 
