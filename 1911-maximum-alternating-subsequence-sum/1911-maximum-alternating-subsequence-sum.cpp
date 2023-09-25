class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
        ll evenMax = nums[0];
        ll oddMax = 0;
        ll res = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++){
            ll curEven = oddMax + nums[i];
            ll curOdd = evenMax - nums[i];
            evenMax = max(evenMax, curEven);
            oddMax = max(oddMax, curOdd);
            res = max(res, max(evenMax, oddMax));
        }
        return res;
    }
};