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
    TreeNode first, second, prev;
    void dfs(TreeNode cur){
        if (cur == null) return;
        dfs(cur.left);
        if (prev != null){
            if (cur.val < prev.val){
                if (first == null){
                    first = prev;
                    second = cur;
                } else {
                    second = cur;
                }
            }
        }
        prev = cur;
        dfs(cur.right);
    }
    public void recoverTree(TreeNode root) {
        dfs(root);
        System.out.println(first.val + " " + second.val);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
}