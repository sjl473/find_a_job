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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>();
        }
        if(root->left == nullptr && root->right == nullptr) {
            int val = root->val;
            vector<int> result;
            result.push_back(val);
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while(q.empty() == false) {
            int counter = q.size();
            int a = q.back()->val;
            result.push_back(a);
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                counter--;
                q.pop();
            }
        }
        return result;
    }
};
