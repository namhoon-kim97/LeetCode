class Solution:
    def lower(self, nums, target):
        st = 0
        en = len(nums)
        while st < en:
            mid = (st + en) // 2
            if nums[mid] < target:
                st = mid + 1
            elif nums[mid] > target:
                en = mid
            else:
                en = mid
                flag = True
        return st

    def upper(self, nums, target):
        st = 0
        en = len(nums)
        while st < en:
            mid = (st + en) // 2
            if nums[mid] <= target:
                st = mid + 1
            elif nums[mid] > target:
                en = mid
            else:
                en = mid
                flag = True
        return st

    def b_search(self, nums, target):
        st = 0
        en = len(nums)
        while st < en:
            mid = (st + en) // 2
            if nums[mid] < target:
                st = mid + 1
            elif nums[mid] > target:
                en = mid
            else:
                return True
        return False

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lower_idx = self.lower(nums, target)
        upper_idx = self.upper(nums, target)
        if self.b_search(nums, target):
            return [lower_idx, upper_idx - 1]
        return [-1, -1]