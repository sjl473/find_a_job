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
// public static void recursionPostorderTraversal(TreeNode root) {
//     if (root != null) {
//         recursionPostorderTraversal(root.left);
//         recursionPostorderTraversal(root.right);
//         System.out.print(root.val + " ");
//     }
// }

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return true;
        }
        vector<int> v = vector<int>();
        InorderTraversal(root, &v);
        for(int i = 0; i < v.size() - 1; i++) {
            if(v[i] >= v[i + 1]) {
                return false;
            }
        }    
        return true;
    }
    void InorderTraversal(TreeNode* root, vector<int>* v) {
        if(root != nullptr) {
            InorderTraversal(root->left, v);
                        (*v).push_back(root->val);
            InorderTraversal(root->right, v);
        }
    }
};
