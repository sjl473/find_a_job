
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.empty() == false) {
            ++level;
            int counter = q.size();
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
                --counter;
            }
        }
        return level;
    }
};
