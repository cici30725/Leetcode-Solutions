class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curLen = 1;
        int res = 1;
        for(int i=1; i<arr.size(); i++){
            if(curLen >= 2){
                if(arr[i]>arr[i-1] && arr[i-2]>arr[i-1])
                    curLen++;
                else if(arr[i]<arr[i-1] && arr[i-2]<arr[i-1])
                    curLen++;
                else if(arr[i]<arr[i-1] || arr[i]>arr[i-1])
                    curLen = 2;
                else
                    curLen = 1;
            }
            else if(arr[i] < arr[i-1] || arr[i]>arr[i-1])
                curLen++;
            else
                curLen = 1;
            
            res = max(res, curLen);
        }
        return res;
    }
};