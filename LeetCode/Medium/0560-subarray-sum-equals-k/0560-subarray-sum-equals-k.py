
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sum_count = {0: 1}
        sum = 0
        cnt = 0
        for i in range(len(nums)):
            sum += nums[i]
            if (sum - k) in sum_count:
                cnt += sum_count[sum - k]
            if sum in sum_count:
                sum_count[sum] += 1
            else:
                sum_count[sum] = 1

        return cnt