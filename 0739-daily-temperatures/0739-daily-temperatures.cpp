class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> sk;
        int n = temperatures.size();
        vector<int> sol(n);
        for(int i=n-1; i>=0; i--){
            while(!sk.empty() && sk.top().first <= temperatures[i])
                sk.pop();
            
            if(sk.empty()){
                sol[i] = 0;
            }
            else{
                sol[i] = sk.top().second - i;
            }
            
            sk.push({temperatures[i], i});
        }
        
        return sol;
    }
};