class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        prefix_sums = [0] * (n + 1)
        sum = 0
        for i in range(1, n + 1):
            sum += nums[i - 1]
            prefix_sums[i] = sum

        left = [0] * (n)
        right = [0] * (n)
        st = []
        for i in range(n):
            while st and nums[st[-1]] >= nums[i]:
                st.pop()
            left[i] = st[-1] if st else -1
            st.append(i)

        st = []
        for i in range(n - 1, -1, -1):
            while st and nums[st[-1]] > nums[i]:
                st.pop()
            right[i] = st[-1] if st else n
            st.append(i)

        ret = 0
        for i in range(n):
            left_bound = left[i]
            right_bound = right[i]
            sum = prefix_sums[right_bound] - prefix_sums[left_bound + 1]
            product = nums[i] * sum
            ret = max(ret, product)

        return ret % MOD
