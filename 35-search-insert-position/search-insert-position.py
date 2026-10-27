class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        for i, n in enumerate(nums):
            if n == target:
                return i
            elif n > target:
                return i
        return len(nums)
        