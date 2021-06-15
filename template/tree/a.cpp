#include "iostream"
#include "queue"
#include "stack"
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
    static TreeNode* InsertNode(int val, TreeNode* root) {
        if(root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* cursor = root;
        TreeNode* prev = nullptr;
        while(true) {
            if(cursor == nullptr) {
                break;
            }
            prev = cursor;
            if(val >= cursor->data) {
                cursor = cursor->right;
            } else {
                cursor = cursor->left;
            }
        }
        if(val >= prev->data) {
            prev->right = new TreeNode(val);
        } else {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};
static void InOrder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* cursor = root;
    while(true) {
        if(s.empty() && cursor == nullptr) {
            break;
        }
        while(true) {
            if(cursor == nullptr) {
                break;
            }
            s.push(cursor);
            cursor = cursor->left;
        }
        cursor = s.top();
        s.pop();
        // print cursor
        cout << cursor->data << endl;
        cursor = cursor->right;
    }
}
static void PreOrder(TreeNode* root) {
    if(root == nullptr) {
        return ;
    }
    queue<TreeNode*> q;
    TreeNode* cursor = nullptr;
    q.push(root);
    while(true) {
        if(q.empty()) {
            break;
        }
        cursor = q.front();
        q.pop();
        if(cursor->left == nullptr) {

        } else {
            q.push(cursor->left);
        }
        if(cursor->right == nullptr) {

        } else {
            q.push(cursor->right);
        }
    }
}
int main(void) {
    TreeNode* node = new TreeNode(9);
    TreeNode::InsertNode(7, node);
    TreeNode::InsertNode(2, node);
    TreeNode::InsertNode(3, node);
    TreeNode::InsertNode(8, node);
    TreeNode::InsertNode(4, node);
    TreeNode::InsertNode(5, node);
    TreeNode::InsertNode(6, node);
    TreeNode::InsertNode(9, node);
    InOrder(node);
    return 0;
}

