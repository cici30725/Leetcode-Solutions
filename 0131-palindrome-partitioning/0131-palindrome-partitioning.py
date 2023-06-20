class Solution:
    def isPalindrome(self, s: str):
        l = 0
        r = len(s)-1
        while(l<r and s[l]==s[r]):
            l+=1
            r-=1
        return l>=r
        
    def dfs(self, s: str, l: int, cur_list: List[str]):
        if l>=len(s):
            self.sol_list.append(cur_list.copy())
            return
        
        for r in range(l, len(s)):
            if self.isPalindrome(s[l:r+1]):
                cur_list.append(s[l: r+1])
                self.dfs(s, r+1, cur_list)
                cur_list.pop()
    
    def partition(self, s: str) -> List[List[str]]:
        self.sol_list = []
        self.dfs(s, 0, [])
        return self.sol_list
        