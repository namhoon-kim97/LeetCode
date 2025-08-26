/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean dfs(TreeNode cur, int target, int sum){
        if (cur == null) return false;
        if (cur.left == null && cur.right == null){
            if (target == sum + cur.val) return true;
            else return false;
        };
        return dfs(cur.left,target,sum + cur.val) || dfs(cur.right, target, sum + cur.val);
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
}