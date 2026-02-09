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
    bool dfs(TreeNode* root, int sum, int target) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr){
            sum += root->val;
            if (sum == target) return true;
            return false;
        }
        return dfs(root->left, sum + root->val, target) |
               dfs(root->right, sum + root->val, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, 0, targetSum);
    }
};