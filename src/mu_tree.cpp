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
    ret = inorderTraversal(t);

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

char* tree_suits()
{
    mu_run_test(mu_init_tree);
    mu_run_test(mu_midorder_tree);
    mu_run_test(mu_max_depth_of_tree);
    
    return 0;
}
