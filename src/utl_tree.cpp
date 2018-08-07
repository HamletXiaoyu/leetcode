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
#include <queue>
#include <stack>

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

vector<int> inorder_traversal(TreeNode* root)
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

int max_depth_of_tree(TreeNode* root)
{
    if (NULL == root)
        return 0;
    int left, right;
    left = max_depth_of_tree(root->left);
    right = max_depth_of_tree(root->right);
    
    return left > right ? left+1 : right+1;
}

int min_depth_of_tree(TreeNode* root)
{
    if (NULL == root)
        return 0;
    if (NULL == root->left && NULL == root->right)
        return 1;
    if (NULL == root->left)
        return min_depth_of_tree(root->right) + 1;
    else if (NULL == root->right)
        return min_depth_of_tree(root->left) + 1;
    else {
        int left = min_depth_of_tree(root->left);
        int right = min_depth_of_tree(root->right);
        return left < right ? left + 1 : right + 1;
    }
}

vector<vector<int> > level_order2(TreeNode* root)
{
    vector<vector<int> > ret;
    if (NULL == root)
        return ret;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> one_level;
        int size = q.size();
        for (int i = 0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();
            one_level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ret.insert(ret.begin(), one_level);
    }
    return ret;
}

bool is_same_tree(struct TreeNode* p, struct TreeNode* q)
{
    if (NULL==p && NULL==q)
        return true;
    if (NULL==p || NULL==q)
        return false;
    if (p->val == q->val)
        return is_same_tree(p->left, q->left) && is_same_tree(p->right,q->right);
    else
        return false;
}

bool symmetric_func(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;
    if (left && !right || !left && right || left->val != right->val)
        return false;
    return symmetric_func(left->left, right->right) && symmetric_func(left->right, right->left);
}

bool is_symmetric(TreeNode *root)
{
    if (NULL == root)
        return true;
    return symmetric_func(root->left, root->right);
}

int num_trees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

vector<vector<int> > zigzag_level_order(TreeNode *root)
{
    vector<vector<int> >res;
    if (!root) return res;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    vector<int> out;
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            TreeNode *cur = s1.top();
            s1.pop();
            out.push_back(cur->val);
            if (cur->left) s2.push(cur->left);
            if (cur->right) s2.push(cur->right);
        } 
        if (!out.empty()) res.push_back(out);
        out.clear();
        while (!s2.empty()) {
            TreeNode *cur = s2.top();
            s2.pop();
            out.push_back(cur->val);
            if (cur->right) s1.push(cur->right);
            if (cur->left) s1.push(cur->left);
        }
        if (!out.empty()) res.push_back(out);
        out.clear();
    }
    return res;
}
