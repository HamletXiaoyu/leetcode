// utl_list.cpp --- 
// Filename: utl_list.cpp
// Created: Tue Aug 21 21:41:51 2018 (+0800)
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

#include "utl_list.h"

using namespace std;

ListNode* init_list(vector<int>& nums)
{
    if (nums.size() <= 0)
        return NULL;
    ListNode* head, *p;
    head = new ListNode(nums[0]);
    p = head;
    for (int i = 1; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

ListNode* add_two_numbers_helper(ListNode* l1, ListNode* l2, int carry)
{
    ListNode* node = NULL;
    if (l1 && l2) {
        node = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry) / 10;
        node->next = add_two_numbers_helper(l1->next, l2->next, carry);
    } else if (l1 && !l2) {
        node = new ListNode((l1->val + carry) % 10);
        carry = (l1->val + carry) / 10;
        node->next = add_two_numbers_helper(l1->next, NULL, carry);
    } else if (!l1 && l2) {
        node = new ListNode((l2->val + carry) % 10);
        carry = (l2->val + carry) / 10;
        node->next = add_two_numbers_helper(NULL, l2->next, carry);
    } else {
        if (carry != 0)
            node = new ListNode(carry);
    }
    return node;
}

ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
{
    if (NULL == l1)
        return l2;
    if (NULL == l2)
        return l1;
    return add_two_numbers_helper(l1, l2, 0);
}
