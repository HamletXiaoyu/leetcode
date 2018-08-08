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
    
    return 0;
}
