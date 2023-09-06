class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq_m;
        for(int i : nums)
            freq_m[i]+=1;
        
        vector<int> arr(n+1, 0); // arr[i] = # distinct ele with i freq
        for(auto& [k, v] : freq_m){
            arr[v] += 1;
        }
        
        vector<int> cum(n+1, 0); // cum[i] = # elements with >=i freq
        cum[n] = arr[n];
        for(int i=n-1; i>=1; i--){
            cum[i] = cum[i+1] + arr[i];
        }
        
        
        int l = 0, r = n+1;
        while(r-l>1){
            int m = (l+r)/2;
            if(cum[m]>=k){
                l = m;
            }
            else{
                r = m;
            }
        }
        
        // lowest freq is l
        vector<int> sol;
        for(auto& [k, v] : freq_m){
            if(v >= l)
                sol.push_back(k);
        }
        return sol;
    }
};