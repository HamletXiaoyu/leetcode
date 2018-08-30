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

char* string_suites()
{
    mu_run_test(mu_z_convert);
    mu_run_test(mu_roman_to_int);
    mu_run_test(mu_int_to_roman);
    mu_run_test(mu_length_of_lastword);
    
    return 0;
}
