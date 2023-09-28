class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int n = intervals.size();
        if(n==0)
            return {newInterval};
        
        int left_i = 0;
        while(left_i < n && intervals[left_i][1] < newInterval[0])
            left_i++;
        
        int right_i = n-1;
        while(right_i >= 0 && intervals[right_i][0] > newInterval[1])
            right_i--;
        
        for(int i=0; i<left_i; i++)
            sol.push_back(intervals[i]);
        
        int cur_l = newInterval[0], cur_r = newInterval[1];
        for(int i=left_i; i<=right_i; i++){
            cur_l = min(cur_l, intervals[i][0]);
            cur_r = max(cur_r, intervals[i][1]);
        }
        
        sol.push_back({cur_l, cur_r});
        
        for(int i=right_i+1; i<n; i++)
            sol.push_back(intervals[i]);
        
        return sol;
    }
};