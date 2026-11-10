class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count = collections.Counter(nums)
        return heapq.nlargest(k, count, key=lambda x: count[x])