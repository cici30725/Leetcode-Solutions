class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]=='1')
            return false;
        
        queue<int> q;
        q.push(0);
        for(int i=1; i<n; i++){
            if(s[i]=='1')
                continue;
            while(!q.empty() && i-q.front()>maxJump){
                q.pop();
            }
            
            if(!q.empty() && i-q.front()>=minJump){
                q.push(i);
                if(i==n-1)
                    return true;
            }
        }
        
        return false;
    }
};