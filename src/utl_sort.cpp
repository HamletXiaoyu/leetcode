// utl_sort.cpp --- 
// Filename: utl_sort.cpp
// Created: Thu Oct 18 21:42:24 2018 (+0800)
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

#include "utl_sort.h"
#include <vector>
#include <string>

using namespace std;

vector<Interval> merge_interval(vector<Interval>& intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < b.start;});
    vector<Interval> res{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
        if (res.back().end < intervals[i].start) {
            res.push_back(intervals[i]);
        } else {
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }   
    return res;
}

void sort_colors(int* nums, int n)
{
    int red = 0, blue = n - 1;
    int tmp;
    for (int i = 0; i <= blue; ++i) {
        if (nums[i] == 0) {
            tmp = nums[i];
            nums[i] = nums[red];
            nums[red] = tmp;
            red++;
        } else if (nums[i] == 2) {
            tmp = nums[i];
            nums[i] = nums[blue];
            nums[blue] = tmp;
            i--;
            blue--;
        } 
    }
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    int i = 0, j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            ++i; ++j;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            ++i;
        }
    }
    return res;
}

bool is_anagram(char* s, char* t)
{
    int len1 = strlen(s);
    int len2 = strlen(t);
    int m[26] = {0};
    if (len1 != len2)
        return false;
    for (int i = 0; i<len1; ++i)
        ++m[s[i] - 'a'];
    for (int i = 0; i<len2; ++i)
        if (--m[t[i] - 'a'] < 0)
            return false;
    return true;
}

string largest_number(vector<int>& nums)
{
    string res;
    sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });
    for (int i = 0; i < nums.size(); ++i) {
        res += to_string(nums[i]);
    }
    return res[0] == '0' ? "0" : res;
}

int h_index(vector<int>& citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); ++i) {
        if (i >= citations[i])
            return i;
    }
    return citations.size();
}

void wiggle_sort(vector<int>& nums)
{
    vector<int> tmp = nums;
    int n = nums.size(), k = (n + 1) / 2, j = n; 
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; ++i) {
        nums[i] = i & 1 ? tmp[--j] : tmp[--k];
    }
}
