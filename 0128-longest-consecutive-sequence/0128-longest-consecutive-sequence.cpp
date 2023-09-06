class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s1, s2;
        for(int i : nums){
            s1.insert(i);
            s2.insert(i);
        }
        
        int best = 0;
        for(int i: s1){
            if(s2.find(i)==s2.end())
                continue;
            s2.erase(i);
            
            int cur = 1;
            for(int j=i+1;;j++){
                if(s2.find(j)==s2.end())
                    break;
                cur++;
                s2.erase(j);
            }
            for(int j=i-1;;j--){
                if(s2.find(j)==s2.end())
                    break;
                cur++;
                s2.erase(j);
            }
            
            best = max(best, cur);
        }
        return best;
    }
};