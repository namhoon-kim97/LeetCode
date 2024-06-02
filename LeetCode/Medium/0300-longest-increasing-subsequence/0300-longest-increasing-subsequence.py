class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # d[i]는 nums[i]를 마지막으로 가지는 LIS
        d = [0] * len(nums)
        d[0] = 1
        for i in range(1, len(nums)):
            d[i] = 1
            for j in range(i - 1, -1, -1):
                if nums[j] < nums[i]:
                    d[i] = max(d[j] + 1, d[i])
        return max(d)