class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                 continue
            r = len(nums) - 1
            l = i + 1
            while (r > l):
                if (nums[i] + nums[r] + nums[l]) == 0:
                    result.append([nums[i], nums[r], nums[l]])
                    l += 1
                    r -= 1
                    while r > l and nums[r] == nums[r+1]:
                        r -= 1
                    while r > l and nums[l] == nums[l-1]:
                        l += 1
                elif (nums[i] + nums[r] + nums[l] > 0):
                    r -= 1
                else:
                    l += 1
           
               
        return result