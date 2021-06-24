// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     template<typename T> static bool isVecSymetric(vector<T>& vec) {
//         if(vec.size() == 0) {
//             return true;
//         }
//         if(vec.size() == 1) {
//             return true;
//         }
//         if(vec.size() % 2 == 0) {
//             int i = 0;
//             int j = vec.size() - 1;
//             while(true) {
//                 if(i >= j) {
//                     return true;
//                 }
//                 if(vec[i] != vec[j]) {
//                     return false;
//                 }
//                 ++i;
//                 --j;
//             }
//         } else {
//             int i = 0;
//             int j = vec.size() - 1;
//             while(true) {
//                 if(i == j) {
//                     return true;
//                 }
//                 if(vec[i] != vec[j]) {
//                     return false;
//                 }
//                 ++i;
//                 --j;
//             }
//         }
//     }
//     bool isSymmetric(TreeNode* node) {
//         if(node == nullptr) {
//             return true;
//         }
//         if(node->left == nullptr && node->right == nullptr) {
//             return true;
//         }
//         TreeNode* root = node;
//         queue<TreeNode*> q;
//         q.push(root);
//         vector<bool> vec;
//         vector<int> vec1;
//         while(!q.empty()) {
//             int counter = q.size();
//             vector<int>().swap(vec1);
//             vector<bool>().swap(vec);
//             while(counter != 0) {
//                 if(q.front()->left) {
//                     q.push(q.front()->left);
//                     vec1.push_back(q.front()->left->val);
//                     vec.push_back(true);
//                 } else {
//                     vec.push_back(false);
//                 }
//                 if(q.front()->right) {
//                     q.push(q.front()->right);
//                     vec1.push_back(q.front()->right->val);
//                     vec.push_back(true);
//                 } else {
//                     vec.push_back(false);
//                 }
//                 q.pop();
//                 --counter;
//             }
//             if(isVecSymetric(vec) && isVecSymetric(vec1)) {
                
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) {
            return true;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return true;
        }
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty()) {
            int counter1 = q1.size();
            int counter2 = q2.size();
            while(counter1) {
                if(q1.front() == nullptr && q2.front() == nullptr) {
                    --counter1;
                    --counter2;
                    q1.pop();
                    q2.pop();
                    continue;
                }
                if(nullptr == q1.front() || nullptr == q2.front()) {
                    return false;
                }
                if(q1.front()->val != q2.front()->val) {
                    return false;
                }
                q1.push(q1.front()->left);
                q1.push(q1.front()->right);
                q2.push(q2.front()->right);
                q2.push(q2.front()->left);
                --counter1;
                --counter2;
                q1.pop();
                q2.pop();
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isSymmetric(TreeNode *root) {
//         TreeNode *left, *right;
//         if (!root)
//             return true;
        
//         queue<TreeNode*> q1, q2;
//         q1.push(root->left);
//         q2.push(root->right);
//         while (!q1.empty() && !q2.empty()){
//             left = q1.front();
//             q1.pop();
//             right = q2.front();
//             q2.pop();
//             if (NULL == left && NULL == right)
//                 continue;
//             if (NULL == left || NULL == right)
//                 return false;
//             if (left->val != right->val)
//                 return false;
//             q1.push(left->left);
//             q1.push(left->right);
//             q2.push(right->right);
//             q2.push(right->left);
//         }
//         return true;
//     }
// };
