
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        int dst = 0;
        preOrder(root, &dst, targetSum, &v);
        return v;
    } 
    void preOrder(TreeNode* root, int* dst, int src, vector<vector<int>>* v) {
        TreeNode* prev = nullptr;
        TreeNode* cursor = root;
        stack<TreeNode*> s;
        vector<int> small;
        while(cursor != nullptr || s.empty() == false) {
            while(cursor != nullptr) {
                s.push(cursor);
                small.push_back(cursor->val);
                if(cursor->val + *dst == src) {
                    if(cursor->left == nullptr && cursor->right == nullptr) {
                        (*v).push_back(small);
                    }
                    *dst += cursor->val;
                } else {
                    *dst += cursor->val;
                }
                cursor = cursor->left;
            }
            cursor = s.top();
            if(cursor->right != nullptr && cursor->right != prev) {
                cursor = cursor->right;
            } else {
                auto a = s.top();
                s.pop();
                *dst -= a->val;
                small.pop_back();     
                prev = cursor;
                cursor = nullptr;
            }
        }
    }
};
