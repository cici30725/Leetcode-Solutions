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
class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> parents;
    BSTIterator(TreeNode* root) {
        while(root){
            parents.push(root);
            root = root->left;
        }
        cur = root;
    }
    
    int next() {
        // cout<<"next"<<endl;
        if(cur!=nullptr && cur->right!=nullptr){
            cur = cur->right;
            while(cur->left){
                parents.push(cur);
                cur = cur->left;
            }
            // cout<<cur->val<<endl;
            return cur->val;
        }
        else{
            cur = parents.top();
            parents.pop();
            // cout<<cur->val<<endl;
            return cur->val;
        }
    }
    
    bool hasNext() {
        // cout<<"hasNext"<<endl;
        if(cur!=nullptr && cur->right!=nullptr)
            return true;
        else
            return parents.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */