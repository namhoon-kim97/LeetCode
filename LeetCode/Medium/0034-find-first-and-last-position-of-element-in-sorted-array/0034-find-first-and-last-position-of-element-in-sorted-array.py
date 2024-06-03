class Solution:
    def lower(self, nums, target):
        st = 0
        en = len(nums)
        while st < en:
            mid = (st + en) // 2
            if nums[mid] < target:
                st = mid + 1
            else:
                en = mid
        return st

    def upper(self, nums, target):
        st = 0
        en = len(nums)
        while st < en:
            mid = (st + en) // 2
            if nums[mid] <= target:
                st = mid + 1
            else:
                en = mid
        return st

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lower_idx = self.lower(nums, target)
        upper_idx = self.upper(nums, target)

        if lower_idx == len(nums) or nums[lower_idx] != target:
            return [-1, -1]
        return [lower_idx, upper_idx - 1]