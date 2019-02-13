/*
Description:
    Inorder traversal of a binary tree.

Time Complexity:
    O(N), where N is the number of nodes in the tree, and each node of the tree is visited once.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> nodes;
        std::vector<int> res;
        
        TreeNode* curr_node = root;
        if(!root) {
            return res;
        }
        do {
            while(curr_node) {
                nodes.push(curr_node);
                curr_node = curr_node->left;
            }
            res.push_back(nodes.top()->val);
            curr_node = nodes.top()->right;
            nodes.pop();
        } while(!nodes.empty() || curr_node);
        return res;
    }
};