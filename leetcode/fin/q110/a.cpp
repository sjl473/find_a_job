
class Solution {
public:
    void traverse(vector<TreeNode*>* v, TreeNode* root) {
        if(root != nullptr) {
            traverse(v, root->right);
            traverse(v, root->left);
            (*v).push_back(root);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        if(root->right == root->left && root->left == nullptr) {
            return true;
        }
        vector<TreeNode*> v = vector<TreeNode*>();
        traverse(&v, root);
        for(int i = 0; i < v.size(); i++) {
            if(std::abs(getHeight(v[i]->left) - getHeight(v[i]->right)) > 1) {
                return false;
            }
        }
        return true;
    }
    int getHeight(TreeNode* root) {
        if(root == nullptr) {
            return 1;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return 2;
        }
        queue<TreeNode*> q;
        q.push(root);
        int result = 1;
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
                counter--;
                q.pop();
            }
        }
        return result;
    }
};
