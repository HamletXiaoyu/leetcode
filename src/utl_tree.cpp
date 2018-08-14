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
#include <algorithm>

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

vector<int> pre_order_traversal(TreeNode* root)
{
    vector<int> ret;
    if (!root)
        return ret;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        ret.push_back(cur->val);
        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
    }
    return ret;
}

vector<int> post_order_traversal(TreeNode* root)
{
    vector<int> ret;
    if (!root)
        return ret;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        ret.insert(ret.begin(), cur->val);
        if (cur->left)
            s.push(cur->left);
        if (cur->right)
            s.push(cur->right);
    }
    return ret;
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

int postorder_for_tilt(TreeNode* node, int& res)
{
    if (!node)
        return 0;
    int left_sum = postorder_for_tilt(node->left, res);
    int right_sum = postorder_for_tilt(node->right, res);
    res += abs(left_sum - right_sum);
    return left_sum + right_sum + node->val;
}

int tilt_of_tree(TreeNode* root)
{
    int res = 0;
    postorder_for_tilt(root, res);
    return res;
}

TreeNode* invert_tree(TreeNode* root)
{
    if (!root)
        return NULL;
    TreeNode *tmp = root->left;
    root->left  = invert_tree(root->right);
    root->right = invert_tree(tmp);
    return root;
}

struct TreeNode* sorted_array_to_bst_func(vector<int>& nums, int left, int right)
{
    if (left > right)
        return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = nums[(int)((left+right)/2)];
    root->left  = sorted_array_to_bst_func(nums, left, (int)((left+right)/2)-1);
    root->right = sorted_array_to_bst_func(nums, (int)((left+right)/2)+1,right);
    return root;
}

struct TreeNode* sorted_array_to_bst(vector<int>& nums)
{
    return sorted_array_to_bst_func(nums, 0, nums.size()-1);
}

int check_depth(TreeNode *root)
{
    if (!root)
        return 0;
    int left = check_depth(root->left);
    if (left == -1)
        return -1;
    int right = check_depth(root->right);
    if (right == -1)
        return -1;
    int diff = abs(left - right);
    if (diff > 1)
        return -1;
    else return 1 + max(left, right);
}

bool is_balanced(TreeNode *root)
{
    if (check_depth(root) == -1)
        return false;
    else return true;
}

int sum_nembers_dfs(TreeNode *root, int num)
{
    if (!root)
        return 0;
    num = num * 10 + root->val;
    if (!root->left && !root->right)
        return num;
    return sum_nembers_dfs(root->left, num) + sum_nembers_dfs(root->right, num);
}

int sum_nembers(TreeNode *root)
{
    return sum_nembers_dfs(root, 0);
}

void sum_of_left_leaf_func(TreeNode *root, bool left, int &sum)
{
    if (!root)
        return;
    if (!root->left && !root->right && left)
        sum += root->val;
    sum_of_left_leaf_func(root->left, true, sum);
    sum_of_left_leaf_func(root->right, false, sum);
}

int sum_of_left_leaf(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return 0;
    int ret = 0;
    sum_of_left_leaf_func(root->left, true, ret);
    sum_of_left_leaf_func(root->right, false, ret);

    return ret;
}

vector<double> average_of_levels(TreeNode *root)
{
    vector<double> ret;
    if (NULL == root)
        return ret;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        double sum = 0.0;
        int size = q.size();
        for (int i = 0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ret.push_back(sum / size);
    }
    return ret;
}

void flatten_tree_to_list(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        flatten_tree_to_list(root->left);
    if (root->right)
        flatten_tree_to_list(root->right);
    
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while (root->right)
        root = root->right;
    root->right = tmp;
}

void binary_tree_paths_helper(TreeNode* node, string out, vector<string>& res)
{
    if (!node->left && !node->right)
        res.push_back(out + to_string(node->val));
    if (node->left)
        binary_tree_paths_helper(node->left, out + to_string(node->val) + "->", res);
    if (node->right)
        binary_tree_paths_helper(node->right, out + to_string(node->val) + "->", res);
}

vector<string> binary_tree_paths(TreeNode* root)
{
    vector<string> res;
    if (root)
        binary_tree_paths_helper(root, "", res);
    return res;
}

bool has_path_sum(struct TreeNode* root, int sum)
{
    if (root == NULL) 
        return false;
    if (root->left == NULL && root->right == NULL && root->val == sum ) 
        return true;
    return has_path_sum(root->left, sum - root->val) || has_path_sum(root->right, sum - root->val);
}

void find_mode_helper(TreeNode* node, TreeNode*& pre,
                      int& cnt, int& mx, vector<int>& res)
{
    if (!node)
        return;
    find_mode_helper(node->left, pre, cnt, mx, res);
    if (pre) {
        cnt = (node->val == pre->val) ? cnt + 1 : 1;
    }
    if (cnt >= mx) {
        if (cnt > mx) res.clear();
        res.push_back(node->val);
        mx = cnt;
    } 
    pre = node;
    find_mode_helper(node->right, pre, cnt, mx, res);
}

vector<int> find_mode(TreeNode* root)
{
    vector<int> res;
    int mx = 0, cnt = 1;
    TreeNode *pre = NULL;
    find_mode_helper(root, pre, cnt, mx, res);
    return res;
}

TreeNode *
build_tree_from_pre_and_inorder_helper(vector<int> &preorder, int pLeft, int pRight,
                                       vector<int> &inorder, int iLeft, int iRight)
{
    if (pLeft > pRight || iLeft > iRight)
        return NULL;
    int i = 0;
    for (i = iLeft; i <= iRight; ++i) {
        if (preorder[pLeft] == inorder[i]) break;
    }
    TreeNode *cur = new TreeNode(preorder[pLeft]);
    cur->left = build_tree_from_pre_and_inorder_helper(preorder, pLeft + 1,
                                                       pLeft + i - iLeft,
                                                       inorder, iLeft, i - 1);
    cur->right = build_tree_from_pre_and_inorder_helper(preorder, pLeft + i - iLeft + 1,
                                                        pRight, inorder,
                                                        i + 1, iRight);
    return cur;
}

TreeNode *build_tree_from_pre_and_inorder(vector<int> &preorder, vector<int> &inorder)
{
    return build_tree_from_pre_and_inorder_helper(preorder, 0, preorder.size() - 1,
                                                  inorder, 0, inorder.size() - 1);
}

TreeNode *build_tree_from_post_and_inorder_helper(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight)
{
    if (iLeft > iRight || pLeft > pRight)
        return NULL;
    TreeNode *cur = new TreeNode(postorder[pRight]);
    int i = 0;
    for (i = iLeft; i < inorder.size(); ++i) {
        if (inorder[i] == cur->val) break;
    }
    cur->left = build_tree_from_post_and_inorder_helper(inorder, iLeft, i - 1,
                                                        postorder, pLeft, pLeft + i - iLeft - 1);
    cur->right = build_tree_from_post_and_inorder_helper(inorder, i + 1, iRight,
                                                         postorder, pLeft + i - iLeft, pRight - 1);
    return cur;
}

TreeNode *build_tree_from_post_and_inorder(vector<int> &inorder, vector<int> &postorder)
{
    return build_tree_from_post_and_inorder_helper(inorder, 0, inorder.size() - 1,
                                                   postorder, 0, postorder.size() - 1);
}
