class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        mp = {0 : 1}
        curr_sum = 0
        count = 0

        for num in nums:
            curr_sum += num

            mod = ((curr_sum % k) + k) % k

            if mod in mp:
                count += mp[mod]
                mp[mod] += 1
            else:
                mp[mod] = 1

        return count


        