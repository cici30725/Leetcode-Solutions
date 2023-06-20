class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [100000 for _ in range(len(nums))]
        dp[0] = 0
        for i in range(1, len(nums)):
            for j in range(1, min(i+1, 1001)):
                if nums[i-j] >= j:
                    dp[i] = min(dp[i-j]+1, dp[i])
                    
        return dp[-1]