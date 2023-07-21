class Solution {
public:
    double findMedHelper(vector<int>& nums1, vector<int>& nums2, int target){
        int n = nums1.size();
        int m = nums2.size();
        
        int l = -1;
        int r = m;
        while(r-l>1){
            int m = (l+r)/2;
            int pos = (upper_bound(nums1.begin(), nums1.end(), nums2[m])-nums1.begin());
            int smaller_cnt = pos + m+1;
            if(smaller_cnt == target)
                return nums2[m];
            else if(smaller_cnt>target)
                r = m;
            else 
                l = m;
        }
        
        if(l==-1){
            return nums1[target-1];
        }
        else{
            int pos = (upper_bound(nums1.begin(), nums1.end(), nums2[l])-nums1.begin());
            int smaller_cnt = pos + l+1;
            int left = target - smaller_cnt;
            return nums1[pos+left-1];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if((m+n)%2!=0){
            return findMedHelper(nums1, nums2, (m+n)/2+1);
        }
        else{
            double a = findMedHelper(nums1, nums2, (m+n)/2);
            double b = findMedHelper(nums1, nums2, (m+n)/2+1);
            cout<<a<<" "<<b<<endl;
            return (a+b)/2;
        }
    }
};