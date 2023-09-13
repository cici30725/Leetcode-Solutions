class Solution {
public:
    vector<string> children(string& s){
        vector<string> res;
        for(int i=0; i<4; i++){
            string up = s, down = s;
            if(up[i]=='9')
                up[i] = '0';
            else
                up[i]+=1;
            if(down[i]=='0')
                down[i] = '9';
            else
                down[i]-=1;
            res.push_back(up);
            res.push_back(down);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit;
        for(string& s : deadends){
            visit.insert(s);
        }
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            string& u = cur.first;
            int val = cur.second;
            if(visit.find(u)!=visit.end())
                continue;
            visit.insert(u);
            
            if(u == target)
                return val;
            
            for(auto v : children(u)){
                q.push({v, val+1});
            }
        }
        return -1;
    }
};