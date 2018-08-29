// utl_string.cpp --- 
// Filename: utl_string.cpp
// Created: Tue Aug 28 22:30:35 2018 (+0800)
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

#include "utl_string.h"
#include <vector>

using namespace std;

string z_convert(string& s, int rows)
{
    if (rows <= 1)
        return s;
    string res = "";
    int size = 2 * rows - 2;
    for (int i = 0; i < rows; ++i) {
        for (int j = i; j < s.size(); j += size) {
            res += s[j];
            int tmp = j + size - 2 * i;
            if (i != 0 && i != rows - 1 && tmp < s.size())
                res += s[tmp];
        }
    }
    return res;
}

int roman_to_int(string s)
{
    int ret = 0, i = 0;
    int cnt = s.size();
    while (i < cnt) {
        if (s[i] == 'M') {
            ret += 1000;
            i += 1;
        } else if ( s[i] == 'D') {
            ret += 500;
            i += 1;
        } else if ( s[i] == 'C') {
            if ( i != cnt -1 && s[i+1] == 'D') {
                ret += 400;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'M') {
                ret += 900;
                i += 2;
            } else {
                ret += 100;
                i += 1;
            }
        }else if (s[i] == 'L') {
            ret += 50;
            i += 1;
        } else if ( s[i] == 'X') {
            if ( i != cnt -1 && s[i+1] == 'L') {
                ret += 40;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'C') {
                ret += 90;
                i += 2;
            } else {
                ret += 10;
                i += 1;
            }
        } else if ( s[i] == 'V') {
            ret += 5;
            i += 1;
        } else if ( s[i] == 'I') {
            if ( i != cnt -1 && s[i+1] == 'V') {
                ret += 4;
                i += 2;
            } else if ( i != cnt -1 && s[i+1] == 'X') {
                ret += 9;
                i += 2;
            } else {
                ret += 1;
                i += 1;
            }
        }
    }
    return ret;
}

string int_to_roman(int num)
{
    string res = "";
    string v1[] = {"", "M", "MM", "MMM"};
    string v2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string v3[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string v4[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
}
