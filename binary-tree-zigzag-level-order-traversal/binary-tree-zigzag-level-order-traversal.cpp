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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> sol;
        int i = 0;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            for(int j=0; j<size; j++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                tmp.push_back(cur->val);
            }
            if(i%2==1)
                reverse(tmp.begin(), tmp.end());
            sol.push_back(tmp);
            i++;
        }
        return sol;
    }
};