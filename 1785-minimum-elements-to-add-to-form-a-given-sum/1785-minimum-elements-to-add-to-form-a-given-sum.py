class Solution(object):
    def minElements(self, nums, limit, goal):
        """
        :type nums: List[int]
        :type limit: int
        :type goal: int
        :rtype: int
        """
        sum = 0
        for n in nums:
            sum += n

        diff = abs(sum-goal)

        # print(float(diff)/limit)

        return int(ceil(float(diff)/limit))
        