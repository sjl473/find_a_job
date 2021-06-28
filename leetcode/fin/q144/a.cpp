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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>();
        }
        if(root->left == nullptr && root->right == nullptr) {
            auto my_vec = vector<int>();
            my_vec.push_back(root->val);
            return my_vec;
        }
        stack<TreeNode*> s;
        s.push(root);
        auto my_vec = vector<int>();
        while(s.empty() == false) {
            auto top_ele = s.top();
            my_vec.push_back(top_ele->val);
            s.pop();
            if(top_ele->right != nullptr) {
                s.push(top_ele->right);
            }
            if(top_ele->left != nullptr) {
                s.push(top_ele->left);
            }
        }
        return my_vec;
    }
};
