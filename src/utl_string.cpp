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
