// mu_list.cpp --- 
// Filename: mu_list.cpp
// Created: Tue Aug 21 21:54:16 2018 (+0800)
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
#include "utl_list.h"

char* mu_init_list()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    ListNode* head = init_list(nums);

    mu_assert(NULL != head, "");
    mu_assert(1 == head->val, "");
    mu_assert(2 == head->next->val, "");
    mu_assert(3 == head->next->next->val, "");
    return 0;
}

char* mu_add_two_numbers()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    ListNode* head1 = init_list(nums);
    nums.clear();
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    ListNode* head2 = init_list(nums);
    ListNode* ret = add_two_numbers(head1, head2);
    // 7->0->8
    mu_assert(NULL != ret, "");
    mu_assert(7 == ret->val, "");
    mu_assert(0 == ret->next->val, "");
    mu_assert(8 == ret->next->next->val, "");

    {
        vector<int> nums;
        nums.push_back(5);
        ListNode* head1 = init_list(nums);
        ListNode* head2 = init_list(nums);
        ListNode* ret = add_two_numbers(head1, head2);
        mu_assert(NULL != ret, "");
        mu_assert(0 == ret->val, "");
        mu_assert(1 == ret->next->val, "");
    }
    return 0;
}

char* mu_swap_pairs()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ListNode* head1 = init_list(nums);
    ListNode* ret = swap_pairs(head1);
    mu_assert(2 == ret->val, "");
    mu_assert(1 == ret->next->val, "");
    mu_assert(4 == ret->next->next->val, "");
    mu_assert(3 == ret->next->next->next->val, "");
    return 0;
}

char* mu_add_two_numbers2()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    ListNode* head1 = init_list(nums);
    nums.clear();
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    ListNode* head2 = init_list(nums);
    ListNode* ret = add_two_numbers2(head1, head2);
    // 7->8->0->7
    mu_assert(NULL != ret, "");
    mu_assert(7 == ret->val, "");
    mu_assert(8 == ret->next->val, "");
    mu_assert(0 == ret->next->next->val, "");
    mu_assert(7 == ret->next->next->next->val, "");
    
    return 0;
}

char* mu_sort_list()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    ListNode* head = init_list(nums);
    ListNode* ret = merge_sort_list(head);
    mu_assert(NULL != ret, "");
    mu_assert(2 == ret->val, "");
    mu_assert(3 == ret->next->val, "");
    mu_assert(4 == ret->next->next->val, "");
    mu_assert(7 == ret->next->next->next->val, "");

    return 0;
}

char* mu_rotate_right()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    ListNode* head = init_list(nums);
    ListNode* ret = rotate_right(head, 4);
    mu_assert(NULL != ret, "");
    mu_assert(2 == ret->val, "");
    mu_assert(0 == ret->next->val, "");
    mu_assert(1 == ret->next->next->val, "");
    
    return 0;
}

char* mu_has_cycle()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ListNode* head = init_list(nums);
    mu_assert(false == has_cycle(head), "");
    head->next->next->next->next->next = head->next->next;
    mu_assert(true == has_cycle(head), "");
    
    return 0;
}

char* mu_middle_node()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ListNode* head = init_list(nums);
    ListNode* ret = middle_node(head);
    mu_assert(2 == ret->val, "");
    mu_assert(3 == ret->next->val, "");
    mu_assert(4 == ret->next->next->val, "");

    return 0;
}

char* mu_reverse_list()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ListNode* head = init_list(nums);
    ListNode* ret = reverse_list(head);
    mu_assert(4 == ret->val, "");
    mu_assert(3 == ret->next->val, "");
    mu_assert(2 == ret->next->next->val, "");

    return 0;
}

char* mu_reverse_list_r()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ListNode* head = init_list(nums);
    ListNode* ret = reverse_list_r(head);
    mu_assert(4 == ret->val, "");
    mu_assert(3 == ret->next->val, "");
    mu_assert(2 == ret->next->next->val, "");

    return 0;
}

char* mu_insertion_sort_list()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    ListNode* head = init_list(nums);
    ListNode* ret = insertion_sort_list(head);
    mu_assert(NULL != ret, "");
    mu_assert(2 == ret->val, "");
    mu_assert(3 == ret->next->val, "");
    mu_assert(4 == ret->next->next->val, "");
    mu_assert(7 == ret->next->next->next->val, "");

    return 0;
}

char* mu_delete_duplicates()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);    
    ListNode* head = init_list(nums);
    ListNode* ret = delete_duplicates(head);
    mu_assert(NULL != ret, "");
    mu_assert(-1 == ret->val, "");
    mu_assert(0 == ret->next->val, "");
    mu_assert(2 == ret->next->next->val, "");
    mu_assert(3 == ret->next->next->next->val, "");
    mu_assert(4 == ret->next->next->next->next->val, "");
    
    return 0;
}

char* mu_delete_duplicates2()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);    
    ListNode* head = init_list(nums);
    ListNode* ret = delete_duplicates2(head);
    mu_assert(NULL != ret, "");
    mu_assert(-1 == ret->val, "");
    mu_assert(2 == ret->next->val, "");
    
    return 0;
}

char* list_suits()
{
    mu_run_test(mu_init_list);
    mu_run_test(mu_add_two_numbers);
    mu_run_test(mu_add_two_numbers2);
    mu_run_test(mu_swap_pairs);
    mu_run_test(mu_sort_list);
    mu_run_test(mu_rotate_right);
    mu_run_test(mu_has_cycle);
    mu_run_test(mu_middle_node);
    mu_run_test(mu_reverse_list);
    mu_run_test(mu_reverse_list_r);
    mu_run_test(mu_insertion_sort_list);
    mu_run_test(mu_delete_duplicates);
    mu_run_test(mu_delete_duplicates2);
    
    return 0;
}
