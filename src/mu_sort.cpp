// mu_sort.cpp --- 
// Filename: mu_sort.cpp
// Created: Thu Oct 18 21:43:01 2018 (+0800)
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
#include "utl_sort.h"

using namespace std;

char* mu_sort_colors()
{
    int nums[] = {2,0,2,1,1,0};
    sort_colors(nums, 6);
    mu_assert(nums[0] == 0, "");
    mu_assert(nums[1] == 0, "");
    mu_assert(nums[2] == 1, "");
    mu_assert(nums[3] == 1, "");
    mu_assert(nums[4] == 2, "");
    mu_assert(nums[5] == 2, "");
    int nums2[] = {2};
    sort_colors(nums2, 1);
    mu_assert(nums2[0] == 2, "");
    int nums3[] = {2,2};
    sort_colors(nums3, 2);
    mu_assert(nums3[0] == 2, "");
    mu_assert(nums3[1] == 2, "");
    
    return 0;
}

char* sort_suites()
{
    mu_run_test(mu_sort_colors);
    
    return 0;
}
