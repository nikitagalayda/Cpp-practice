/*
Description:
    Postorder traversal of a binary tree using an unordered_map.

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::unordered_set<TreeNode*> vis;
        
        TreeNode* curr_node = root; 
        
        while(curr_node && vis.count(curr_node) == 0) {
            if(curr_node->left && vis.count(curr_node->left) == 0) {
                curr_node = curr_node->left;
            }
            else if(curr_node->right && vis.count(curr_node->right) == 0) {
                curr_node = curr_node->right;
            }
            else {
                res.push_back(curr_node->val);
                vis.insert(curr_node);
                // Reset the traversal with newly visited node in the map.
                curr_node = root;
            }
        }
        
        return res;
    }
};