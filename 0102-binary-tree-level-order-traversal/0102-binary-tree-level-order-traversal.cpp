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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> sol;
        while(!q.empty()){
            int size = q.size();
            vector<int> cur_lvl;
            for(int i=0; i<size; i++){
                TreeNode* curNode = q.front();
                q.pop();
                cur_lvl.push_back(curNode->val);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            
            sol.push_back(cur_lvl);
        }
        
        return sol;
    }
};