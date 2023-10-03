class Solution {
public:
    int trap(vector<int>& height) {
        int l_max = height[0], r_max = height[height.size()-1];
        int l = 1, r = height.size()-2;
        int res = 0;
        while(l<=r){
            if(l_max < r_max){
                res += max(l_max - height[l], 0);
                l_max = max(l_max, height[l]);
                l++;
            }
            else{
                res += max(r_max - height[r], 0);
                r_max = max(r_max, height[r]);
                r--;
            }
        }
        
        return res;
    }
};