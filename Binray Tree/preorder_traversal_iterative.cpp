/*
Description:
    Preorder traversal of a binary tree.

Time Complexity:
    O(N), where N is the number of nodes in the tree, and each node of the tree is visited once.
*/

#include <stack>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> nodes;
        std::vector<int> res;

        if(root == NULL) {
            return res;
        }
        nodes.push(root);
        while(!nodes.empty()) {
            TreeNode *curr_node = nodes.top();
            nodes.pop();
            res.push_back(curr_node->val);

            // Push the left node after the right node because in that 
            // case the left node will be popped first. 
            if(curr_node->right) {
                nodes.push(curr_node->right);
            }
            if(curr_node->left) {
                nodes.push(curr_node->left);
            }
        }
        return res;
    }
};