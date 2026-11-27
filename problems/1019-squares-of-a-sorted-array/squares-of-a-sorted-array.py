class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        l = 0
        r = len(nums) - 1
        for i, n in enumerate(nums):
            nums[i] = n*n

        result = [0] * len(nums) 
        write = len(nums) - 1
        while (write >= 0):
            if nums[l] > nums[r]:
                result[write] = nums[l]
                l += 1
            else:
                result[write] = nums[r]
                r -= 1
            write -= 1
        return result
