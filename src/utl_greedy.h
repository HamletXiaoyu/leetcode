/* utl_greedy.h --- 
 * Filename: utl_greedy.h
 * Created: Sat Sep 22 22:03:25 2018 (+0800)
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

#ifndef UTL_GREEDY_H_
#define UTL_GREEDY_H_

#include <iostream>

// leetcode 44
bool is_match(char* s, char* p);
// leetcode 738
int monotone_increasing_digits(int N);
// leetcode 55
bool can_jump(int* nums, int numsSize);
// leetcode 45
int jump(int* nums, int n);
// leetcode 122
int max_profit(int* prices, int n);
// leetcode 121
int max_profit1(int* prices, int n);
// leetcode 714
int max_profit_with_fee(int* prices, int n, int fee);
// leetcode 134
int can_complete_circuit(int* gas, int gas_size, int* cost, int cost_size);
// leetcode 455
int find_content_children(int* g, int g_size, int* s, int s_size);
//int find_content_children(std::vector<int>& g, std::vector<int>& s);
// leetcode 135
int candy(int* ratings, int n);
// leetcode 392
bool is_subsequence(std::string s, std::string t);
// leetcode 402
std::string remove_k_digits(std::string num, int k);

#endif
