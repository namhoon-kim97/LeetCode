class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        sum = 0
        arr = []
        for i in nums:
            sum += i
            arr.append(sum)

        st = 0
        en = st 
        ret = sys.maxsize
        while st < len(nums) and en < len(nums):
            if arr[en] - arr[st] + nums[st] >= target:
                ret = min(ret, en - st + 1)
            if arr[en] - arr[st] + nums[st] > target:
                st += 1
            elif arr[en] - arr[st] + nums[st] < target:
                en += 1
            else:
                st += 1
                en += 1

        if ret == sys.maxsize:
            return 0
        else:
            return ret