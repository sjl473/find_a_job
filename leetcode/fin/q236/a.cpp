

class Solution {
public:

// void getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& v) {
//     stack<TreeNode*> s;
//     TreeNode* cursor = root;
//     TreeNode* pre = nullptr;
//     while(cursor != nullptr || s.empty() == false) {
//         while(cursor != nullptr) {
//             s.push(cursor);
//             v.push_back(cursor);
//             cursor = cursor->left;
//         }
//         °¢°¢ cursor = s.top();
//         if(cursor->right £°= nullptr && °£°£ cursor->right != prev) {
//             cursor = cursor->right;
//         } else {
//             // ”“±ﬂ «ø’÷∏’Î
//             s.pop();
//             v.pop_back();
//             °£°£ prev = cursor;
//            °£°£  cursor = nullptr; // ƒ≥Ω⁄µ„ «÷’÷π◊¥Ã¨
//             // ”“±ﬂ‘¯æ≠±ªœÚ◊Û∑ΩœÚ◊ﬂµƒ ±∫Úæ≠”…π˝
//         }
//     }
// }








































    void getPath(TreeNode* root, TreeNode* end, vector<TreeNode*>& path) {
        stack<TreeNode*> s;
        TreeNode* cursor = root;
        TreeNode* prev = nullptr;
        while(cursor != nullptr || s.empty() == false) {
            while(cursor != nullptr) {
                s.push(cursor);
                path.push_back(cursor);
                if(cursor == end) {
                    return;
                }
                cursor = cursor->left;
            }
            cursor = s.top();
            if(cursor->right == nullptr || cursor->right == prev) {
                path.pop_back();
                s.pop();
                prev = cursor;
                cursor = nullptr;
            } else {
                cursor = cursor->right;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        getPath(root, p, v1);
        getPath(root, q, v2);
        int min_path = std::min(v1.size(), v2.size());
        TreeNode* last = nullptr;
        for(int i = 0; i < min_path; i++) {
            if(v1[i] != v2[i]) {
                return last;
            }
            last = v1[i];
        }
        return last;
    }
};

