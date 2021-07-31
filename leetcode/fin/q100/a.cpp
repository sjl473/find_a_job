class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string a = "";
        string b = "";
        traverse(&a, p);
        traverse(&b, q);
        return a == b;
    }
    void traverse(string* a, TreeNode* root) {
        if(root == nullptr) {
            *a = "";
            return ;
        }
        queue<TreeNode*> q;
        q.push(root);
        *a += std::to_string(root->val);
        while(q.empty() == false) {
            int counter = q.size();
            *a += "-";
            while(counter != 0) {
                if(q.front()->left != nullptr) {
                    q.push(q.front()->left);
                    *a += std::to_string(q.front()->left->val);
                } else {
                    *a += "*";
                }
                if(q.front()->right != nullptr) {
                    q.push(q.front()->right);
                    *a += std::to_string(q.front()->right->val);
                } else {
                    *a += "+";
                }
                --counter;
                q.pop();
            }
        }
    }
};
