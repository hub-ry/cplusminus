class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = prices[0]
        best = 0
        for price in prices:
            if (price - min_price > best):
                best = (price - min_price)
        
            if (price < min_price):
                min_price = price
        return best