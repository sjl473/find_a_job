
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> tree_stk;
        stack<string> path_stk;
        vector<string> result;
        if(root == nullptr) {
            return result;
        }
        tree_stk.push(root);
        path_stk.push(std::to_string(root->val));
        while(tree_stk.empty() == false) {
            TreeNode* node = tree_stk.top();
            tree_stk.pop();
            
            string path = path_stk.top();
            path_stk.pop();
            if(node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
            }
            if(node->right != nullptr) {
                tree_stk.push(node->right);
                path_stk.push(path + "->" + std::to_string(node->right->val));
            }
            if(node->left != nullptr) {
                tree_stk.push(node->left);
                path_stk.push(path + "->" + std::to_string(node->left->val));
            }
        }
        return result;
    }
};


