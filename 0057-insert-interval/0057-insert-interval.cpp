class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int n = intervals.size();
        
        int i=0;
        while(i<n){
            if(intervals[i][1] < newInterval[0])
                sol.push_back(intervals[i]);
            else if(intervals[i][0] > newInterval[1])
                break;
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        sol.push_back(newInterval);
        sol.insert(sol.end(), intervals.begin()+i, intervals.end());
        return sol;
    }
};