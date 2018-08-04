/* utl_tree.h --- 
 * Filename: utl_tree.h
 * Created: Wed Aug  1 22:18:26 2018 (+0800)
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

#ifndef UTL_TREE_H_
#define UTL_TREE_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* utl_init_tree(string& s, int &pos);

// traversal
void utl_preorder_r(struct TreeNode* t);
void utl_midorder_r(struct TreeNode* t);
void utl_postorder_r(struct TreeNode* t);

// non Recursive
vector<int> inorderTraversal(TreeNode* root);

//depth
int max_depth_of_tree(TreeNode* root);
int min_depth_of_tree(TreeNode* root);

#endif
