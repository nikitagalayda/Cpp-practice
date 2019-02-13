/*
Description:
    Pre-order traversal of a binary tree.

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
    std::vector<int> visited;
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode *curr_node = root;
        
        if(curr_node) {
            visited.push_back(curr_node->val);
            preorderTraversal(curr_node->left);
            preorderTraversal(curr_node->right);
        }
        return visited;
    }

};