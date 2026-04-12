/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode* node, bool isLeft) {
        if (node == nullptr) return 0;
        if (isLeft) {
            if (node->left == nullptr && node->right== nullptr) return node->val;
        }
        return traverse(node->left, true) + traverse(node->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return traverse(root->left, true) + traverse(root->right, false);
    }
};