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
    vector<int> temp;
    void inorder(TreeNode* cur) {
        if (cur == nullptr)
            return;
        inorder(cur->left);
        temp.push_back(cur->val);
        inorder(cur->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ret = INT_MAX;
        for (int i = 0; i < temp.size() - 1; ++i) {
            ret = min(abs(temp[i] - temp[i + 1]), ret);
        }
        return ret;
    }
};