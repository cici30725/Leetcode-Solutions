class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int total = nums1.size() + nums2.size();
        int half = total/2;
        
        int l = 0, r = nums1.size()-1;
        while(true){
            int m = floor((l+r)/2.0);
            int left = half - (m+1) - 1;
            
            double nums1Left = (m>=0 ? nums1[m] : -INFINITY);
            double nums1Right = (m<(int)nums1.size()-1 ? nums1[m+1] : INFINITY);
            double nums2Left = (left>=0 ? nums2[left] : -INFINITY);
            double nums2Right = (left<(int)nums2.size()-1 ? nums2[left+1] : INFINITY);
            
            if(nums1Left <= nums2Right && nums2Left <= nums1Right){
                double leftVal = max(nums1Left, nums2Left);
                double rightVal = min(nums1Right, nums2Right);
                if(total%2==0)
                    return (leftVal + rightVal)/2;
                else
                    return rightVal;
            }
            else if(nums1Left > nums2Right)
                r = m-1; 
            else
                l = m+1;
        }
    }
};