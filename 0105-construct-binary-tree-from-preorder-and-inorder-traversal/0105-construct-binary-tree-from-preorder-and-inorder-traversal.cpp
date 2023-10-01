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
    int i = 0;
    int p = 0;
    
    TreeNode* build(int stopVal, vector<int>& preorder, vector<int>& inorder){
        if(i < inorder.size() && inorder[i]!=stopVal){
            TreeNode* curNode = new TreeNode{preorder[p]};
            p++;
            curNode->left = build(curNode->val, preorder, inorder);
            i++;
            curNode->right = build(stopVal, preorder, inorder);
            return curNode;
        }
        else
            return nullptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(-5000, preorder, inorder);
    }
};