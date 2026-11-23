class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        for i in range(len(nums) // 2 + 1):
                if (nums[i] == target or nums[-i] == target):
                    return True
        return False