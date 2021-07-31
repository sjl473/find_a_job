/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }   
        queue<TreeNode*> q;
        q.push(root);
        int temp = INT_MAX;
        while(q.empty() == false) {
            int counter = q.size();
            if(q.front() != nullptr) {
                temp = q.front()->val;
            }
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                --counter;
                q.pop();
            }
        }
        return temp;
    }
};
