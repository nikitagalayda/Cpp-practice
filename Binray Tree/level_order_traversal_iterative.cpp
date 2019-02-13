/*
Description:
    Level-order traversal of a binary tree using an unordered_map.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector< std::vector<int> > res;
        std::queue<TreeNode*> q;
        std::vector<int> curr_row;
        int curr_level_items = 1;           // Keeps track of which items in queue
                                            // are on which level.
        if(!root) {
            return {};
        }
        q.push(root);
        
        while(!q.empty()) {
            if(q.front()->left) {
                q.push(q.front()->left);
            }
            if(q.front()->right) {
                q.push(q.front()->right);
            }
            curr_row.push_back(q.front()->val);
            q.pop();
            if(--curr_level_items == 0) {
                curr_level_items = q.size();    // All of the children of the previously iterated nodes
                res.push_back(curr_row);        // are on the next level.
                curr_row.clear();
            }
        }
        return res;
    }
};