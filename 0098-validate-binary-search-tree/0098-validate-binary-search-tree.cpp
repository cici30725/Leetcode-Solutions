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
    bool flag = true;
    int num;
    
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        
        if(flag){
            num = root->val;
            flag = false;
        }
        else if(root->val <= num){
            return false;
        }
        else{
            num = root->val;
        }
        
        return isValidBST(root->right);
    }
};