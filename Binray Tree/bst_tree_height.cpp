/*
Description:
    Given the root of a binary tree, returns the height of the tree. Assuming that the root is level 1;

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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        if(leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
};