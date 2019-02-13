Description:
    Given an integer sum, and a root of a Binary Tree, returns whether or not there is a path in the tree, where the values of the nodes on the path add up to sum. This is a Top-down approach.

Time Complexity:
    At most O(N) where N is the number of nodes in the tree. The worst time complexity occurs if the correct path is the last to be iterated over.
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {        
        return recurSum(root, 0, sum);
    }
    
    bool recurSum(TreeNode *root, int leftOver, int sum) {
        if(root && !root->left && !root->right && (root->val + leftOver) == sum) {
            return true;
        }
        if(root) {
            if(recurSum(root->left, leftOver + root->val, sum)) {
                return true;
            }
            if(recurSum(root->right, leftOver + root->val, sum)) {
                return true;
            }
        }
        return false;
    }
};