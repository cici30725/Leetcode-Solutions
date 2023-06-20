/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sol = 0;
    void dfs(TreeNode* cur, int cur_max){
        if(cur==nullptr)
            return;
        
        if(cur->val >= cur_max)
            sol+=1;
        
        dfs(cur->left, max(cur_max, cur->val));
        dfs(cur->right, max(cur_max, cur->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        dfs(root, -1e5);
        return sol;
    }
};