class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> arr(2*n, 0);
        for(int i=0; i<n; i++)
            arr[i] = gas[i] - cost[i];
        for(int i=n; i<2*n; i++)
            arr[i] = arr[i-n];
        
        int cur = 0;
        int l = -1, r = 0;
        for(; r<2*n; r++){
            cur += arr[r];
            while(l<r && cur < 0){
                cur -= arr[++l];
            }
            
            if(r-l == n && cur >= 0)
                return (l+1)%n;
        }
        
        return -1;
    }
};