/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curNode, unordered_map<Node*, Node*>& um){
        if(um.find(curNode)!=um.end()){
            return um[curNode];
        }
        
        Node* dupNode = new Node{curNode->val};
        um[curNode] = dupNode;
        for(Node* v : curNode->neighbors){
            dupNode->neighbors.push_back(dfs(v, um));
        }
        return dupNode;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*> um;
        return dfs(node, um);
    }
};