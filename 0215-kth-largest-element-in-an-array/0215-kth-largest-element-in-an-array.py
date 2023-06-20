class Solution:
    def rec(self, l, r, nums, k) -> int:
        if l==r:
            return nums[l]
        pivot = nums[r]
        i = -1
        j = 0
        while j<r:
            if nums[j]<= pivot:
                i+=1
                nums[i], nums[j] = nums[j], nums[i]
            j+=1
            
        nums[i+1], nums[r] = nums[r], nums[i+1]
        left = i-l+1
        right = r-i
        if r-(i+1)+1==k:
            return nums[i+1]
        elif k <= right:
            return self.rec(i+1, r, nums, k)
        else:
            return self.rec(l, i, nums, k-right)
        
                
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.rec(0, len(nums)-1, nums, k)
        