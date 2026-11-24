class Solution:
    def fourSumCount(self, nums1: list[int], nums2: list[int], nums3: list[int], nums4: list[int]) -> int:
        adds1 = {}
        adds2 = {}
        # i think that we can just use a hashmap to count
        n = len(nums1)
        for i in range(n):
            for j in range(n):
                a1 = nums1[i] + nums2[j]
                adds1[a1] = adds1.get(a1, 0) + 1
                a2 = nums3[i] + nums4[j]
                adds2[a2] = adds2.get(a2, 0) + 1     
        result = 0
        # now we have to loop through the results
        for key, num in adds1.items():
            if (0 - key) in adds2:
                result += num * adds2[-key]
        return result