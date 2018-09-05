// mu_string.cpp --- 
// Filename: mu_string.cpp
// Created: Tue Aug 28 22:32:33 2018 (+0800)
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
#include "utl_string.h"
#include <vector>

using namespace std;

char* mu_z_convert()
{
    string s = "PAYPALISHIRING";
    string ret = z_convert(s, 3);
    mu_assert(ret == "PAHNAPLSIIGYIR", "");
    ret = z_convert(s, 4);
    mu_assert(ret == "PINALSIGYAHRPI", "");
    
    return 0;
}

char* mu_roman_to_int()
{
    string s = "III";
    int ret = roman_to_int(s);
    mu_assert(3 == ret, "expect 3, but get %d", ret);
    ret = roman_to_int("MCMXCIV");
    mu_assert(1994 == ret, "expect 1994, but get %d", ret);
    
    return 0;
}

char* mu_int_to_roman()
{
    string s = int_to_roman(3);
    mu_assert(s == "III", "");
    s = int_to_roman(1994);
    mu_assert(s == "MCMXCIV", "");
    
    return 0;
}

char* mu_length_of_lastword()
{
    string s = "hello world  ";
    mu_assert(length_of_lastword(s) == 5, "");
    
    return 0;
}

char* mu_multiply()
{
    mu_assert(multiply("2", "3") == "6", "");
    mu_assert(multiply("12", "12") == "144", "");
    mu_assert(multiply("15", "15") == "225", "");
    return 0;
}

char* mu_add_strings()
{
    mu_assert(add_strings("2", "3") == "5", "");
    mu_assert(add_strings("12", "12") == "24", "");
    mu_assert(add_strings("15", "15") == "30", "");
    mu_assert(add_strings("10", "90") == "100", "");
    mu_assert(add_strings("0", "0") == "0", "");
    return 0;
}

char* mu_longest_common_prefix()
{
    vector<string> strs;
    strs.push_back("fly");
    strs.push_back("flower");
    strs.push_back("flow");
    mu_assert(longest_common_prefix(strs) == "fl", "");

    return 0;
}

char* mu_add_binary()
{
    mu_assert(add_binary("1", "11") == "100", "");
    mu_assert(add_binary("1010", "1011") == "10101", "");
    
    return 0;
}

char* mu_restore_ips()
{
    string s = "25525511135";
    std::vector<std::string> ret = restore_ips(s);
    mu_assert(2 == ret.size(), "");
    mu_assert("255.255.11.135" == ret[0], "");
    mu_assert("255.255.111.35" == ret[1], "");
    
    return 0;
}

char* mu_first_uniq_char()
{
    string s = "leetcode";
    mu_assert(0 == first_uniq_char(s), "");

    return 0;
}

char* mu_is_palindrome_str()
{
    string s = "A man, a plan, a canal: Panama";
    mu_assert(true == is_palindrome_str(s), "");
    mu_assert(false == is_palindrome_str("race a car"), "");

    return 0;
}

char* mu_count_segments()
{
    mu_assert(count_segments("hello, my name is hamlet") == 5, "");
    mu_assert(count_segments("       ") == 0, "");
    mu_assert(count_segments("  , , , , ,    aiyoubucuo ") == 6, "");
    
    return 0;
}

char* mu_compress()
{
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('b');
    mu_assert(compress(chars) == 4, "");
    mu_assert(chars[0] == 'a', "");
    mu_assert(chars[1] == '3', "");
    mu_assert(chars[2] == 'b', "");
    mu_assert(chars[3] == '4', "");
    
    return 0;
}

char* mu_compare_version()
{
    mu_assert(compare_version("1.0", "1.0.1") == -1, "");
    mu_assert(compare_version("1.0.7.5.2.4", "1.0.7.5.1") == 1, "");
    mu_assert(compare_version("1.0.7", "1.0.7") == 0, "");

    return 0;
}

char* mu_reverse_vowels()
{
    mu_assert(reverse_vowels("hello") == "holle", "");
    mu_assert(reverse_vowels("leetcode") == "leotcede", "");
    
    return 0;
}

char* mu_can_construct()
{
    mu_assert(false == can_construct("aa", "ab"), "");
    mu_assert(true == can_construct("aa", "aab"), "");
    
    return 0;
}

char* mu_detect_capitaluse()
{
    mu_assert(detect_capitaluse("China") == true, "");
    mu_assert(detect_capitaluse("USA") == true, "");
    mu_assert(detect_capitaluse("GooglE") == false, "");
    
    return 0;
}

char* mu_reverse_str()
{
    mu_assert("bacdfeg" == reverse_str("abcdefg", 2), "");
    
    return 0;
}

char* mu_find_lus_length()
{
    mu_assert(3 == find_lus_length("abc", "adc"), "");
    
    return 0;
}

char* mu_check_record()
{
    mu_assert(true == check_record("PPALLP"), "");
    mu_assert(false == check_record("PPALLPLLL"), "");

    return 0;
}

char* mu_reverse_words()
{
    mu_assert("s'teL ekat edoCteeL tsetnoc" ==
              reverse_words("Let's take LeetCode contest"), "");
    
    return 0;
}

char* mu_reverse_words1()
{
    string s = "the sky is blue";
    reverse_words1(s);
    mu_assert(s == "blue is sky the", "");
    return 0;
}

char* mu_number_to_words()
{
    mu_assert("One Hundred Twenty Three" == number_to_words(123), "");
    mu_assert("One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
              == number_to_words(1234567), "");
    
    return 0;
}

char* mu_to_lower_case()
{
    mu_assert("hello" == to_lower_case("HeLLO"), "");

    return 0;
}

char* mu_rotated_digits()
{
    mu_assert(4 == rotated_digits(10), "");
    
    return 0;
}

char* mu_optimal_division()
{
    vector<int> nums;
    nums.push_back(1000);
    nums.push_back(100);
    nums.push_back(10);
    nums.push_back(2);
    mu_assert("1000/(100/10/2)" == optimal_division(nums), "");
    
    return 0;
}

char* mu_is_number()
{
    mu_assert(true == is_number("0"), "");
    mu_assert(true == is_number("0.1"), "");
    mu_assert(true == is_number("2e10"), "");
    mu_assert(false == is_number("abc"), "");
    mu_assert(false == is_number("e9"), "");
    mu_assert(false == is_number("3.e"), "");
    mu_assert(true == is_number("3.e9"), "");
    mu_assert(true == is_number(" 32.34506"), "");
    
    return 0;
}

char* mu_repeated_substring_pattern()
{
    mu_assert(true == repeated_substring_pattern("abab"), "");
    mu_assert(true == repeated_substring_pattern("abcabc"), "");
    mu_assert(false == repeated_substring_pattern("abc"), "");
    mu_assert(false == repeated_substring_pattern("aba"), "");
    
    return 0;
}

char* string_suites()
{
    mu_run_test(mu_z_convert);
    mu_run_test(mu_roman_to_int);
    mu_run_test(mu_int_to_roman);
    mu_run_test(mu_length_of_lastword);
    mu_run_test(mu_multiply);
    mu_run_test(mu_add_strings);
    mu_run_test(mu_longest_common_prefix);
    mu_run_test(mu_add_binary);
    mu_run_test(mu_restore_ips);
    mu_run_test(mu_first_uniq_char);
    mu_run_test(mu_is_palindrome_str);
    mu_run_test(mu_count_segments);
    mu_run_test(mu_compress);
    mu_run_test(mu_compare_version);
    mu_run_test(mu_reverse_vowels);
    mu_run_test(mu_can_construct);
    mu_run_test(mu_detect_capitaluse);
    mu_run_test(mu_reverse_str);
    mu_run_test(mu_find_lus_length);
    mu_run_test(mu_check_record);
    mu_run_test(mu_reverse_words);
    mu_run_test(mu_reverse_words1);
    mu_run_test(mu_number_to_words);
    mu_run_test(mu_to_lower_case);
    mu_run_test(mu_rotated_digits);
    mu_run_test(mu_optimal_division);
    mu_run_test(mu_is_number);
    mu_run_test(mu_repeated_substring_pattern);
    
    return 0;
}
