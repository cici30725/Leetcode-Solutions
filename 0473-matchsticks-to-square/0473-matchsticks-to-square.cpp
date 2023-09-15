class Solution {
public:
    bool dfs(int idx, vector<int>& m, array<int, 4>& buckets, int target){
        if(idx==m.size())
            return true;
        for(int i=0; i<buckets.size(); i++){
            if(buckets[i] + m[idx] <= target) {
                buckets[i] += m[idx];
                if(dfs(idx+1, m, buckets, target))
                    return true;
                buckets[i] -= m[idx];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        if(total % 4 !=0)
            return false;
        array<int, 4> buckets{};
        return dfs(0, matchsticks, buckets, total/4);
    }
};