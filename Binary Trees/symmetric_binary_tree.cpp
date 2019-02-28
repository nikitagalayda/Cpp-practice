/*
Description: 
	Given a binary tree, returns whether or not the tree is symmetric.
	Symmetric Binary Tree:
		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	Asymmetric Binary Tree:
		1
	   / \
	  2   2
	   \   \
	    4   3

Time Complexity:
	O(N) where N is the number of nodes in the tree. We must traverse every
	node in order to check for symmetry.
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        return isSymmetricRecursive(root->left, root->right);
    }
    
    bool isSymmetricRecursive(TreeNode *left, TreeNode *right) {
        if(!right || !left) {
            return right == left;       // if one is null, return false. If both null, return true
        }
        if(left->val != right->val) {
           return false;
        }
        // Pass symmetric subtrees for inspection.
        return isSymmetricRecursive(left->left, right->right) && isSymmetricRecursive(left->right, right->left);
        }
};