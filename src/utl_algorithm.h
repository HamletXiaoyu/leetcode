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

#include <vector>

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

#endif 
