class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        arr = [None for _ in range(len(temperatures))]
        for i in range(len(temperatures)-1, -1, -1):
            while len(stack)>0 and stack[-1][0] <= temperatures[i]:
                stack.pop()
            if len(stack) == 0:
                arr[i] = 0
            else:
                arr[i] = stack[-1][1] - i
            stack.append([temperatures[i], i])
        return arr
        