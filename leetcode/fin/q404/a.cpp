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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while(q.empty() == false) {
            int counter = q.size();
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);  
                    if(q.front()->left->left == nullptr && q.front()->left->right == nullptr) {
                        sum += q.front()->left->val;   
                    }
                } 
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                } 
                --counter;
                q.pop();
            }
        }
        return sum;
    }
};



