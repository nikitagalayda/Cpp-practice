/*
Description:
	Given an integer sum, and a root of a Binary Tree, returns whether or not there is a path in the tree, where the values of the nodes on the path add up to sum. This is a Bottom-up approach.

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
        if(!root) {
            return false;
        }
        else {
            bool ans = false;
            
            int sumSub = sum - root->val;
            
            if((sumSub == 0) && (root->right == NULL) && (root->left == NULL)) {
                return true;
            }
            else {
                if(root->left) {
                    ans = ans || hasPathSum(root->left, sumSub);
                }
                if(root->right) {
                    ans = ans || hasPathSum(root->right, sumSub);
                }
            }
            return ans;
        }
    }
};