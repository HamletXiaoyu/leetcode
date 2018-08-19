/* mu_tree.cpp --- 
 * Filename: mu_tree.cpp
 * Created: Mon Jul 30 23:01:11 2018 (+0800)
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

#include "minunit.h"
#include "mu_suites.h"
#include "utl_tree.h"

char* mu_init_tree()
{
    string s = "1#23";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    utl_preorder_r(t);
    printf("\n");
    utl_midorder_r(t);
    printf("\n");
    utl_postorder_r(t);
    printf("\n");

    mu_assert(NULL != t, "");
    mu_assert(1 == t->val, "");
    mu_assert(NULL == t->left, "");

    return 0;
}

char* mu_midorder_tree()
{
    string s = "1#23";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);

    vector<int> ret;
    ret = inorder_traversal(t);

    mu_assert(ret.size() == 3, "");
    mu_assert(ret[0] == 1, "");
    mu_assert(ret[1] == 3, "");
    mu_assert(ret[2] == 2, "");
    
    return 0;
}

char* mu_max_depth_of_tree()
{
    {
        string s = "1#23";
        int pos = -1;
        struct TreeNode* t;
        t = utl_init_tree(s, pos);
        int ret = max_depth_of_tree(t);

        mu_assert(ret == 3, "");
    }
    {
        string s = "39##25##7##";
        int pos = -1;
        struct TreeNode* t;
        t = utl_init_tree(s, pos);
        int ret = max_depth_of_tree(t);
        mu_assert(ret == 3, "");
    }
    
    return 0;
}

char* mu_min_depth_of_tree()
{
    {
        string s = "1#23";
        int pos = -1;
        struct TreeNode* t;
        t = utl_init_tree(s, pos);
        int ret = min_depth_of_tree(t);

        mu_assert(ret == 3, "");
    }
    {
        string s = "39##25##7##";
        int pos = -1;
        struct TreeNode* t;
        t = utl_init_tree(s, pos);
        int ret = min_depth_of_tree(t);
        mu_assert(ret == 2, "");
    }
    
    return 0;
}

char* mu_level_order2()
{
    string s = "39##25##7##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    vector<vector<int> > ret = level_order2(t);

    mu_assert(ret.size() == 3, "");
    mu_assert(ret[0].size() == 2, "");
    mu_assert(ret[1].size() == 2, "");
    mu_assert(ret[2].size() == 1, "");
    mu_assert(ret[0][0] == 5, "");
    mu_assert(ret[0][1] == 7, "");
    mu_assert(ret[1][0] == 9, "");
    mu_assert(ret[1][1] == 2, "");
    mu_assert(ret[2][0] == 3, "");
    return 0;
}

char* mu_num_trees()
{
    int ret = num_trees(3);
    mu_assert(ret == 5, "");
    return 0;
}

char* mu_tilt_of_tree()
{
    string s = "12##3##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int tilt = tilt_of_tree(t);
    mu_assert(tilt == 1, "");
    
    return 0;
}

char* mu_sorted_array_to_bst()
{
    int a[] = {-10,-3,0,5,9};
    vector<int> nums;
    for(int i=0; i<5; ++i)
        nums.push_back(a[i]);
    struct TreeNode* root = sorted_array_to_bst(nums);

    mu_assert(NULL != root, "");
    mu_assert(0 == root->val, "");
    mu_assert(-10 == root->left->val, "");
    mu_assert(5 == root->right->val, "");
    return 0;
}

char* mu_sum_nembers()
{
    string s = "495##1##0##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int num = sum_nembers(t);
    mu_assert(num == 1026, "");
    return 0;
}

char* mu_sum_of_left_leaf()
{
    string s = "495##1##0##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int num = sum_of_left_leaf(t);

    mu_assert(num == 5, "");
    return 0;
}

char* mu_post_order_traversal()
{
    string s = "1#23#";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    vector<int> ret = post_order_traversal(t);

    mu_assert(ret.size() == 3, "");
    mu_assert(ret[0] == 3, "");
    mu_assert(ret[1] == 2, "");
    mu_assert(ret[2] == 1, "");
    
    return 0;
}

char* mu_pre_order_traversal()
{
    string s = "1#23#";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    vector<int> ret = pre_order_traversal(t);

    mu_assert(ret.size() == 3, "");
    mu_assert(ret[0] == 1, "");
    mu_assert(ret[1] == 2, "");
    mu_assert(ret[2] == 3, "");
    
    return 0;
}

char* mu_binary_tree_paths()
{
    string s = "12#5##3##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    vector<string> ret = binary_tree_paths(t);

    mu_assert(ret.size() == 2, "");
    mu_assert(ret[0] == "1->2->5", "");
    mu_assert(ret[1] == "1->3", "");
    return 0;
}

char* mu_has_path_sum()
{
    string s = "12#5##3##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    mu_assert(has_path_sum(t, 8), "");
    mu_assert(has_path_sum(t, 4), "");
    mu_assert(!has_path_sum(t, 5), "");
    
    return 0;
}

char* mu_build_tree_from_pre_and_inorder()
{
    vector<int> preorder, inorder;

    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);

    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);
  //   3
  //  / \
  // 9  20
  //   /  \
  //  15   7
    TreeNode *t = build_tree_from_pre_and_inorder(preorder, inorder);
    mu_assert(NULL != t, "");
    mu_assert(3 == t->val, "");
    mu_assert(9 == t->left->val, "");
    mu_assert(20 == t->right->val, "");
    return 0;
}

char* mu_find_bottom_left_value()
{
    //     1
    //    / \
    //   2   3
    //  /   / \
    // 4   5   6
    //    /
    //   7
    string s = "124###357###6##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int ret = find_bottom_left_value(t);
    mu_assert(7 == ret, "");
    
    return 0;
}

char* mu_find_second_minimum_value()
{
  //   2
  //  / \
  // 2   5
  //    / \
  //   5   7
    string s = "22##55##7##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int ret = find_second_minimum_value(t);
    mu_assert(ret == 5, "");
    
    return 0;
}

char* mu_right_side_view_of_tree()
{
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
    string s = "12#5##3#4##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    vector<int> ret = right_side_view_of_tree(t);

    mu_assert(3 == ret.size(), "");
    mu_assert(1 == ret[0], "");
    mu_assert(3 == ret[1], "");
    mu_assert(4 == ret[2], "");
    
    return 0;
}

char* mu_construct_maximum_binarytree()
{
// [3,2,1,6,0,5]

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(5);
    TreeNode* t = construct_maximum_binarytree(nums);
    mu_assert(NULL != t, "");
    mu_assert(6 == t->val, "");
    mu_assert(3 == t->left->val, "");
    mu_assert(5 == t->right->val, "");
    return 0;
}

char* mu_width_of_binarytree()
{
    //      1
    //    /   \
    //   3     2
    //  / \     \  
    // 5   3     9
    string s = "135##3##2#9##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int wid = width_of_binarytree(t);
    mu_assert(4 == wid, "");
    return 0;
}

char* mu_count_nodes()
{
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
    string s = "124##5##36###";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    int count = count_nodes(t);
    mu_assert(count == 6, "");
    
    return 0;
}

char* mu_search_bst()
{
    //     4
    //    / \
    //   2   7
    //  / \
    // 1   3
    string s = "421##3##7##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    TreeNode* ret = search_bst(t, 2);

    mu_assert(NULL != ret, "");
    mu_assert(2 == ret->val, "");
    mu_assert(1 == ret->left->val, "");
    mu_assert(3 == ret->right->val, "");
    return 0;
}

char* mu_lowest_common_ancestor_in_bst()
{
   //      _______6______
   //     /              \
   //  ___2__          ___8__
   // /      \        /      \
   // 0      _4       7       9
   //       /  \
   //       3   5
    string s = "620##43##5##87##9##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);
    struct TreeNode* p = new TreeNode(2);
    struct TreeNode* q = new TreeNode(4);
    TreeNode* ret = lowest_common_ancestor_in_bst(t, p, q);
    mu_assert(NULL != ret, "");
    mu_assert(2 == ret->val, "");
    return 0;
}

char* mu_is_valid_bst()
{
  //   5
  //  / \
  // 1   4
  //    / \
  //   3   6
    string s = "51##43##6##";
    int pos = -1;
    struct TreeNode* t;
    t = utl_init_tree(s, pos);

    mu_assert(false == is_valid_bst(t), "");
    
    return 0;
}

char* tree_suits()
{
    mu_run_test(mu_init_tree);
    mu_run_test(mu_midorder_tree);
    mu_run_test(mu_max_depth_of_tree);
    mu_run_test(mu_min_depth_of_tree);
    mu_run_test(mu_level_order2);
    mu_run_test(mu_num_trees);
    mu_run_test(mu_tilt_of_tree);
    mu_run_test(mu_sorted_array_to_bst);
    mu_run_test(mu_sum_nembers);
    mu_run_test(mu_sum_of_left_leaf);
    mu_run_test(mu_post_order_traversal);    
    mu_run_test(mu_pre_order_traversal);
    mu_run_test(mu_binary_tree_paths);
    mu_run_test(mu_has_path_sum);
    mu_run_test(mu_build_tree_from_pre_and_inorder);
    mu_run_test(mu_find_bottom_left_value);
    mu_run_test(mu_find_second_minimum_value);
    mu_run_test(mu_right_side_view_of_tree);
    mu_run_test(mu_construct_maximum_binarytree);
    mu_run_test(mu_width_of_binarytree);
    mu_run_test(mu_count_nodes);
    mu_run_test(mu_search_bst);
    mu_run_test(mu_lowest_common_ancestor_in_bst);
    mu_run_test(mu_is_valid_bst);
    
    return 0;
}
