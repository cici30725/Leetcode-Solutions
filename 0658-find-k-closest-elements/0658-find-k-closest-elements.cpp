class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;
        int cnt = 0;
        while(cnt<k){
            if(r>=arr.size())
                l--;
            else if(l<0)
                r++;
            else{
                int l_len = abs(arr[l] - x), r_len = abs(arr[r] - x);
                if(l_len <= r_len)
                    l--;
                else
                    r++;
            }
            cnt++;
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
};