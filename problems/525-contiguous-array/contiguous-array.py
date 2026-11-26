class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = {}
        count[0] = -1
        total = 0
        longest = 0
        for i, n in enumerate(nums):
            
            if n == 1:
                total += 1
            elif n == 0:
                total -= 1

            if total in count:
               longest = max(longest, i - count[total])
            
            else:
                count[total] = i
        return longest
            