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
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        if(root->left == nullptr && root->left == root->right) {
            return 1;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(q.empty() == false) {
            int counter = q.size();
            ++result;
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                if(q.front()->left == nullptr && q.front()->right == nullptr) {
                    return result;
                }
                q.pop();
                --counter;
            }
        }
        return result;
    }
};
