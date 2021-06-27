
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* pos;
        Find(&pos, x, root);
        if(double(CountTreeNode(pos)) < double(n) / 2) {
            return true;
        }
        if(double(CountTreeNode(pos->left)) > double(n / 2) || double(CountTreeNode(pos->right)) > double(n / 2)) {
            return true;
        }
        return false;
    }
    int CountTreeNode(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int total_counter = 0;
        TreeNode* cursor = root;
        ++total_counter;
        queue<TreeNode*> q;
        q.push(cursor);
        while(q.empty() == false) {
            int qsize = q.size();
            while(qsize != 0) {
                auto temp = q.front();
                if(temp->left != nullptr) {
                    q.push(temp->left);
                    ++total_counter;
                }
                if(temp->right != nullptr) {        $
                    q.push(temp->right);
                    ++total_counter;
                }
                --qsize;
                q.pop();
            }
        }
        return total_counter;
    }
    void Find(TreeNode** pos, int x, TreeNode* root) {
        TreeNode* cursor = root;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int qsize = q.size();
            while(qsize != 0) {
                auto temp = q.front();
                if(temp->val == x) {
                    *pos = temp;
                    return ;
                }
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
                --qsize;
                q.pop();
            }
        }
        return;
    }
};
