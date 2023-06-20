class Solution:
    def jump(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return 0
        l = 0
        r = nums[0]
        farthest = 0
        res = 0
        while r<len(nums)-1:
            for i in range(l, r+1):
                farthest = max(i+nums[i], farthest)
            l = r+1
            r = farthest
            res+=1
            
        return res+1
