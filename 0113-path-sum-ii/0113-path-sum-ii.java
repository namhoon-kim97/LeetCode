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
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> temp = new ArrayList<>();
    void dfs(TreeNode cur, int target){
        if (cur == null) return;
        if (cur.left == null && cur.right == null){
            if (cur.val == target){
                temp.add(cur.val);
                res.add(new ArrayList<>(temp));
                temp.remove(temp.size() - 1);
                return;
            }
            return;
        }
        temp.add(cur.val);
        dfs(cur.left, target - cur.val);
        dfs(cur.right, target - cur.val);
        temp.remove(temp.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
}