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
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int result = 1;
        while(q.empty() == false) {
            int counter = q.size();
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                    ++result;
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                    ++result;
                }
                q.pop();
                --counter;
            }
        }
        return result;
    }
};




