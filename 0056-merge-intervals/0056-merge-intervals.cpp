class Solution {
public:
    bool canMerge(vector<int>& i1, vector<int>& i2){
        return (i1[1] >= i2[0]);
    }
    
    vector<int> mergeInterval(vector<int>& i1, vector<int>& i2){
        return {min(i1[0], i2[0]), max(i1[1], i2[1])};
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> curInterval = intervals[0];
        vector<vector<int>> sol;
        for(int i=1; i<intervals.size(); i++){
            if(canMerge(curInterval, intervals[i])){
                curInterval = mergeInterval(curInterval, intervals[i]);
            }
            else{
                sol.push_back(curInterval);
                curInterval = intervals[i];
            }
        }
        
        sol.push_back(curInterval);
        return sol;
    }
};