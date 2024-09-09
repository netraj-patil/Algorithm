'''
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
'''
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        offset = nums.index(min(nums))
        length = len(nums)
        k = 0
        l = len(nums) -1
        while k<=l:
            mid = (k+l)//2
            if nums[(mid + offset) % length] == target:
                return (mid + offset) % length
            if nums[(mid + offset) % length] > target:
                l = mid - 1
            else:
                k = mid+1
        return -1