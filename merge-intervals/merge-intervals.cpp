class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int cur_l = intervals[i][0], cur_r = intervals[i][1];
            if(cur_l > r){
                sol.push_back({l, r});
                l = cur_l;
                r = cur_r;
            }
            else{
                r = max(cur_r, r);
            }
        }
        sol.push_back({l, r});
        return sol;
    }
};