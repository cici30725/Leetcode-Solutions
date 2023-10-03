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
    void dfs(TreeNode* root, int& k, int& sol){
        if(root==nullptr)
            return;
        
        dfs(root->left, k, sol);
        k--;
        if(k==0){
            sol = root->val;
            return;
        }
        
        dfs(root->right, k, sol);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int sol = 0;
        dfs(root, k, sol);
        return sol;
    }
};