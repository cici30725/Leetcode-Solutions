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
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        
        array<bool, 101> visit{};
        array<Node*,101> dup{};
        
        queue<Node*> q;
        q.push(node);
        dup[node->val] = new Node{node->val};
        
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            if(visit[curNode->val])
                continue;
            visit[curNode->val] = true;
            
            Node* dupNode = dup[curNode->val];
            for(Node* v : curNode->neighbors){
                if(dup[v->val]==nullptr)
                    dup[v->val] = new Node{v->val};
                dupNode->neighbors.push_back(dup[v->val]);
                q.push(v);
            }
        }
        
        return dup[node->val];
    }
};