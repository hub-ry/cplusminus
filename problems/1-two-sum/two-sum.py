class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}

        for i,n in enumerate(nums):
            if (target - n) in seen:
                return (i, seen[target-n])
            seen[n] = i
            