class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [100000 for _ in range(len(nums))]
        dp[0] = 0
        for i in range(len(nums)):
            for j in range(i+1, min(len(nums), i+nums[i]+1)):
                dp[j] = min(dp[j], dp[i]+1)
                    
        return dp[-1]