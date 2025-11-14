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
    public void recoverTree(TreeNode root) {
        TreeNode first = null;
        TreeNode second = null;
        TreeNode prev = null;
        TreeNode cur = root;

        while (cur != null){
            if (cur.left == null){
                if (prev != null && prev.val > cur.val){
                    if (first == null)
                        first = prev;
                    second = cur;
                }
                prev = cur;
                cur = cur.right;
            } else {
                TreeNode pre = cur.left;
                while (pre.right != null  && pre.right != cur)
                    pre = pre.right;
                if (pre.right == null){
                    pre.right = cur;
                    cur = cur.left;
                } else {
                    pre.right = null;
                    if (prev != null && prev.val > cur.val){
                        if (first == null)
                            first = prev;
                        second = cur;
                    }
                    prev = cur;
                    cur = cur.right;
                }
            }
        }
        if (first != null && second != null){
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }
}