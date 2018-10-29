// mu_dp.cpp --- 
// Filename: mu_dp.cpp
// Created: Wed Oct 24 22:55:23 2018 (+0800)
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
#include "utl_dp.h"
#include <string>
#include <vector>

using namespace std;

char* mu_rob()
{
    int num[] = {1, 2, 3, 1};
    mu_assert(4 == rob(num, 4), "");
    
    return 0;
}

char* mu_unique_paths()
{
    mu_assert(3 == unique_paths(3, 2), "");
    mu_assert(28 == unique_paths(7, 3), "");
    return 0;
}

char* mu_num_decodings()
{
    mu_assert(2 == num_decodings("12"), "");
    mu_assert(3 == num_decodings("226"), "");
    
    return 0;
}

char* dp_suites()
{
    mu_run_test(mu_rob);
    mu_run_test(mu_unique_paths);
    mu_run_test(mu_num_decodings);
    
    return 0;
}
