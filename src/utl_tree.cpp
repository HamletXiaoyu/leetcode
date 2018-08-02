// utl_tree.cpp --- 
// Filename: utl_tree.cpp
// Created: Wed Aug  1 22:25:20 2018 (+0800)
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
#include "utl_tree.h"

using namespace std;

struct TreeNode* utl_init_tree(string& s, int &pos)
{
    ++pos;
    struct TreeNode* t;
    if(pos >= s.size())
        return NULL;
    else{
        if(s[pos] == '#')
            return NULL;
        else{
            t = (TreeNode*)malloc(sizeof(TreeNode));
            t->val = s[pos] - '0';
            t->left = utl_init_tree(s, pos);
            t->right = utl_init_tree(s, pos);
        }
    }
    return t;
}

void utl_preorder_r(struct TreeNode* t)
{
    if (NULL != t) {
        printf("%d ", t->val);
        utl_preorder_r(t->left);
        utl_preorder_r(t->right);
    }
}

void utl_midorder_r(struct TreeNode* t)
{
    if (NULL != t) {
        utl_midorder_r(t->left);
        printf("%d ", t->val);
        utl_midorder_r(t->right);
    }
}

void utl_postorder_r(struct TreeNode* t)
{
    if (NULL != t) {
        utl_postorder_r(t->left);
        utl_postorder_r(t->right);
        printf("%d ", t->val);
    }
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (!root)
        return res;
    TreeNode *cur, *pre;
    cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur) pre = pre->right;
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = NULL;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}
