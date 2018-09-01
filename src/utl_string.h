/* utl_string.h --- 
 * Filename: utl_string.h
 * Created: Tue Aug 28 22:28:55 2018 (+0800)
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

#ifndef UTL_STRING_H_
#define UTL_STRING_H_

#include <string>

// leetcode 6
std::string z_convert(std::string& s, int rows);
// leetcode 12
std::string int_to_roman(int num);
// leetcode 13
int roman_to_int(std::string s);
// leetcode 58
int length_of_lastword(std::string s);
// leetcode 43
std::string multiply(std::string num1, std::string num2);
// leetcode 415
std::string add_strings(std::string num1, std::string num2);
// leetcode 14
std::string longest_common_prefix(std::vector<std::string>& strs);
// leetcode 657
bool judge_circle(std::string moves);
// leetcode 67
std::string add_binary(std::string a, std::string b);
// leetcode 93
std::vector<std::string> restore_ips(std::string s);
// leetcode 387
int first_uniq_char(std::string s);
// leetcode 125
bool is_palindrome_str(std::string s);
// leetcode 434
int count_segments(std::string s);
// leetcode 443
int compress(std::vector<char>& chars);

#endif
