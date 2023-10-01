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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl >= pr || il >= ir)
            return nullptr;
        
        int curVal = preorder[pl];
        TreeNode* curNode = new TreeNode{curVal};
        
        int i=il;
        while(i<ir && inorder[i]!=curVal)
            i++;
        
        int leftLen = i - il;
        curNode->left = dfs(preorder, inorder, pl+1, pl+1+leftLen, il, i);
        curNode->right = dfs(preorder, inorder, pl+1+leftLen, pr, i+1, ir);
        return curNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return dfs(preorder, inorder, 0, n, 0, n);
    }
};