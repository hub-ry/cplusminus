class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        return heapq.nsmallest(k, points, key=lambda p: p[0]**2 + p[1]**2)
        

# hands back the k itmes from points with the smallest key. key is a small function to calc istance
