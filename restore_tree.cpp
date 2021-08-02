#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val) {
        this->val = val;
    }
};

class Solution {
public:
    unordered_map<int, int> my_map;
    int index = 0;
public:
    TreeNode *build(vector<int> &pre, int left, int right) {
        if (left <= right) {
            int mid = my_map[pre[index]];
            TreeNode *treeNode = new TreeNode(pre[index]);
            index++;
            treeNode->left = build(pre, left, mid - 1);
            treeNode->right = build(pre, mid + 1, right);
            return treeNode;
        }
        return nullptr;
    }

    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        for (int i = 0; i < in.size(); i++) {
            int value = in[i];
            my_map[value] = i;
        }
        TreeNode *result = build(pre, 0, pre.size() - 1);
        return result;
    }
};


struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (postorderSize == 0 || inorderSize == 0)return NULL;      //叶子结点的左右子树为空

    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];                     //根结点值为后序遍历最后一位

    int left;
    for (left = 0; left < inorderSize; left++) {
        if (inorder[left] == root->val)break;                    //找到中序列表中的根结点，其索引为左子树结点个数
    }
    int right = inorderSize - left - 1;                         //计算右子树结点个数

    root->left = buildTree(inorder, left, postorder, left);        //递归构建左、右子树
    root->right = buildTree(inorder + left + 1, right, postorder + left, right);

    return root;
}


