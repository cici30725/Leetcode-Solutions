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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int in_l, int in_r, int pre_l, int pre_r){
        if(in_r < in_l)
            return nullptr;
        
        int mid_val = preorder[pre_l];
        int idx = 0;
        for(int i = in_l; i<=in_r; i++){
            if(inorder[i]==mid_val){
                idx = i;
                break;
            }
        }
        TreeNode* left = construct(preorder, inorder, in_l, idx-1, pre_l+1, pre_l+(idx-in_l));
        TreeNode* right = construct(preorder, inorder, idx+1, in_r, pre_l+(idx-in_l)+1, pre_r);
        TreeNode* cur = new TreeNode(mid_val);
        cur->left = left;
        cur->right = right;
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return construct(preorder, inorder, 0, n-1, 0, n-1);
    }
};