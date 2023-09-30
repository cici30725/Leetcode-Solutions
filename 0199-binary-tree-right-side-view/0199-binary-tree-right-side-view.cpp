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
    void dfs(TreeNode* root, int lvl, vector<int>& sol){
        if(root==nullptr)
            return;
        
        if(lvl == sol.size())
            sol.push_back(root->val);
        
        dfs(root->right, lvl+1, sol);
        dfs(root->left, lvl+1, sol);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        dfs(root, 0, sol);
        return sol;
    }
};