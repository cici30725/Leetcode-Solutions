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
    List<Integer> arr;
    void dfs(TreeNode cur, int level){
        if(cur==null)
            return;
        
        if(level>=arr.size())
            arr.add(0);
        dfs(cur.left, level+1);
        arr.set(level, cur.val);
        dfs(cur.right, level+1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        arr = new ArrayList<>(); 
        dfs(root, 0);
        return arr;
    }
}