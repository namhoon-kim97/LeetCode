class Solution(object):
    def maxProfit(self, prices):
        # d[i] 는 i번째 까지 최대 이익 팔거나 or 팔지 않거나
        d = [0] * len(prices)
        d[0] = 0
        # d[1] = prices[1] - prices[0]
        min_price = prices[0]
        for i in range(1, len(prices)):
            d[i] = max(d[i - 1], prices[i] - min_price)
            if min_price > prices[i]:
                min_price = prices[i]

        return d[len(prices) - 1]