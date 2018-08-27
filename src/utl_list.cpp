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
#include <stack>

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

void push(struct ListNode** head_ref, int val)
{
    /* allocate node */
    struct ListNode* new_node = new ListNode(val);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void print_list(struct ListNode *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->val);
        node = node->next;
    }
    printf("\n");
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

ListNode* merge_two_sorted_lists(ListNode* l1, ListNode* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode* head = NULL;
    ListNode* p = NULL;
    while (l1 || l2) {
        if (l1 && l2) {
            if (!head) {
                head = l1->val <= l2->val ? new ListNode(l1->val) : new ListNode(l2->val);
                p = head;
                    
            } else {
                p->next = l1->val <= l2->val ? new ListNode(l1->val) : new ListNode(l2->val);
                p = p->next;
            }
            if (l1->val <= l2->val)
                l1 = l1->next;
            else
                l2 = l2->next;
        } else if (l1 && !l2) {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
        } else if (!l1 && l2) {
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
        }
    }
    return head;
}

struct ListNode* remove_nth_from_end(struct ListNode* head, int n)
{
    if (!head->next)
        return NULL;
    struct ListNode *pre = head, *cur = head;
    for (int i = 0; i < n; ++i) 
        cur = cur->next;
    if (!cur) 
        return head->next;
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
}

ListNode *reverse_kgroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy, *cur = head;
    dummy->next = head;
    int i = 0;
    while (cur) {
        ++i;
        if (i % k == 0) {
            pre = reverse_one_group(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}

ListNode *reverse_one_group(ListNode *pre, ListNode *next)
{
    ListNode *last = pre->next;
    ListNode *cur = last->next;
    while(cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}

ListNode* swap_pairs(ListNode* head)
{
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    while (pre->next && pre->next->next) {
        ListNode *t = pre->next->next;
        pre->next->next = t->next;
        t->next = pre->next;
        pre->next = t;
        pre = t->next;
    }
    return dummy->next;
}

ListNode* add_two_numbers2(ListNode* l1, ListNode* l2)
{
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    ListNode *res = new ListNode(0);
    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }
        res->val = sum % 10;
        ListNode *head = new ListNode(sum / 10);
        head->next = res;
        res = head;
        sum /= 10;
    }
    return res->val == 0 ? res->next : res;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    return dummy->next;
}

ListNode* merge_sort_list(ListNode* head)
{
    if (!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head, *pre = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return merge(merge_sort_list(head), merge_sort_list(slow));
}

ListNode* rotate_right(ListNode* head, int k)
{
    if (!head)
        return NULL;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; ++i) {
        cur = cur->next;
    }
    ListNode *newhead = cur->next;
    cur->next = NULL;
    return newhead;
}

bool has_cycle(struct ListNode *head)
{
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
            return true;
    }
    return false;
}

ListNode *get_intersection_node(struct ListNode *head1,
                                struct ListNode *head2)
{
    if (!head1 || !head2)
        return NULL;
    struct ListNode *p1 = head1, *p2 = head2;
    struct ListNode *ret = NULL;
    int len1 = 0, len2 = 0;
    int i;
    while (p1->next) {
        p1 = p1->next;
        ++len1;
    }
    p1 = head1;
    while (p2->next) {
        p2 = p2->next;
        ++len2;
    }
    p2 = head2;
    if (len1 > len2) {
        for (i=0; i<len1-len2; ++i)
            p1 = p1->next;
    } else {
        for (i=0; i<len2-len1; ++i)
            p2 = p2->next;
    }
    while (p1 && p2) {
        if (p1 == p2) {
            ret = p1;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return ret;
}

void quick_sort_list1(ListNode* pBegin , ListNode* pEnd)
{
    if (NULL == pBegin ||
        NULL == pEnd ||
        pBegin == pEnd)
    {
        return;
    }

    ListNode* pFirst = pBegin;
    ListNode* pSecond = pFirst->next;
    
    int nMidValue = pBegin->val;

    while(pSecond != pEnd->next && pSecond != NULL)
    {
        if(pSecond->val < nMidValue)
        {
            pFirst = pFirst->next;
            std::swap(pFirst->val, pSecond->val);
        }

        pSecond = pSecond->next;
    }

    std::swap(pBegin->val, pFirst->val);

    quick_sort_list1(pBegin, pFirst);
    quick_sort_list1(pFirst->next, pEnd);
}

ListNode* get_partion(ListNode* pBegin, ListNode* pEnd)
{
    int val = pBegin->val;
    ListNode* p = pBegin;
    ListNode* q = p->next;
 
    while(q != pEnd)
    {
        if(q->val < val)
        {
            p = p->next;
            swap(p->val, q->val);
        }
 
        q = q->next;
    }
    swap(p->val, pBegin->val);
    return p;
}
 
void quick_sort_list2(ListNode* pBeign, ListNode* pEnd)
{
    if(pBeign != pEnd)
    {
        ListNode* partion = get_partion(pBeign, pEnd);
        quick_sort_list2(pBeign, partion);
        quick_sort_list2(partion->next, pEnd);
    }
}

ListNode* reverse_list(ListNode* head)
{
    if (!head)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = head;
    while (cur->next) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = dummy->next;
        dummy->next = tmp;
    }
    return dummy->next;
}

ListNode* reverse_list_r(ListNode* head)
{

    if (!head || !head->next) 
        return head;
    struct ListNode *p = head;
    head = reverse_list_r(p->next);
    p->next->next = p;
    p->next = NULL;
    return head;
}

ListNode* middle_node(ListNode* head)
{
    ListNode* p1 = head, *p2 = head;
    while (p1 && p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

ListNode* insertion_sort_list(ListNode* head)
{
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    while (head) {
        ListNode *t = head->next;
        cur = dummy;
        while (cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
    }
    return dummy->next;
}

ListNode *merge_k_lists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    int n = lists.size();
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; ++i) {
            lists[i] = merge_two_sorted_lists(lists[i], lists[i + k]);
        }
        n = k;
    }
    return lists[0];
}

ListNode* delete_duplicates(struct ListNode* head)
{
    if (!head)
        return NULL;
    struct ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    struct ListNode* cur = head;
    head = head->next;
    while (head) {
        if (cur->val != head->val) {
            cur->next = head;
            cur = cur->next;
            head = head->next;
        } else {
            head = head->next;
        }
    }
    cur->next = NULL;
    return dummy->next;
}

ListNode* delete_duplicates2(ListNode* head)
{
    if (!head)
        return NULL;
    struct ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    struct ListNode* cur = head;
    struct ListNode* pre = dummy;
    head = head->next;
    int flag = 0;
    while (head) {
        if (cur->val != head->val) {
            if (flag == 0) {
                cur->next = head;
                cur = cur->next;
                head = head->next;
                pre = pre->next;
            } else {
                pre->next = head;
                cur = head;
                head = head->next;
                flag = 0;
            }
        } else {
            head = head->next;
            flag = 1;
        }
    }
    cur->next = NULL;
    if (flag == 1)
        pre->next = NULL;
    return dummy->next;
}

ListNode* partition(ListNode* head, int x)
{
    if (!head) 
        return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *newDummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy, *p = newDummy;
    while (cur->next) {
        if (cur->next->val < x) {
            p->next = cur->next;
            p = p->next;
            cur->next = cur->next->next;
            p->next = NULL;
        } else {
            cur = cur->next;
        }
    }
    p->next = dummy->next;
    return newDummy->next;
}
