class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            if(lhs[0]==rhs[0])
                return lhs[1] >= rhs[1];
            else
                return lhs[0] <= rhs[0];
        });
        
        int max_r = intervals[0][1];
        int res = 0;
        for(int i=1; i<intervals.size(); i++){
            auto& v = intervals[i];
            if(v[1] <= max_r)
                res++;
            max_r = max(max_r, v[1]);
        }
        return intervals.size()-res;
    }
};