/* utl_sort.h --- 
 * Filename: utl_sort.h
 * Created: Thu Oct 18 21:41:33 2018 (+0800)
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

#ifndef UTL_SORT_H_
#define UTL_SORT_H_

#include <iostream>

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
// leetcode 56
std::vector<Interval> merge_interval(std::vector<Interval>& intervals);
// leetcode 75
void sort_colors(int* nums, int n);
// leetcode 350
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

#endif
