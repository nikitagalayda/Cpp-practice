/*
Description:
    Inorder traversal of a binary tree.

Time Complexity:
    O(N), where N is the number of nodes in the tree, and each node of the tree is visited once.
*/
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>

class Solution {
private:
    std::vector<int> res;
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(root) {
            if(root->left) {
                inorderTraversal(root->left);
            }
            res.push_back(root->val);
            if(root->right) {
                inorderTraversal(root->right);
            }
        }
        return res;
    }
};