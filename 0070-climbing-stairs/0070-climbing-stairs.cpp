class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, 0);
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int prev_two_step = 1;
        int prev_one_step = 2;
        for(int i=2; i<n; i++){
            int cur = prev_one_step + prev_two_step;
            prev_two_step = prev_one_step;
            prev_one_step = cur;
        }
        
        return prev_one_step;
    }
};