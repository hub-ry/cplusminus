class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
       seen = {}
       for i, num in enumerate(nums):
        v = target - num
        if v in seen: 
            return [i, seen[v]]
        seen[num] = i 
        
