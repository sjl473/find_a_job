#include "iostream"
#include "queue"
#include "stack"
using namespace std;
class TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    static void InsertNode(int val, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *cursor = root;
        TreeNode *prev = nullptr;
        while (true) {
            if (cursor == nullptr) {
                break;
            }
            prev = cursor;
            if (cursor->val <= val) {
                cursor = cursor->right;
                // left
            } else {
                cursor = cursor->left;
                // right
            }
        }
        if (prev->val <= val) {
            cursor = cursor->right;
        } else {
            cursor = cursor->left;
        }
    }

    static void Print(int val, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *cursor = root;
        queue<TreeNode *> q;
        q.push(cursor);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            // print t->data
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }

    static int TreeHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        int counter = 0;
        while (!q.empty()) {
            counter = q.size();
            ++height;
            while (counter) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                counter--;
            }
        }
        return height;
    }
};
