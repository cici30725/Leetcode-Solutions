class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            int cur = static_cast<int>(ceil(static_cast<double>(dist[i])/speed[i]));
            arr[i] = cur;
        }
        
        sort(arr.begin(), arr.end());
        int i=0;
        for(; i<n; i++){
            if(i>=arr[i])
                break;
        }
        return i;
    }
};