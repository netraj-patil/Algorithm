class Solution:
    def canJump(self, nums: List[int]) -> bool:
        l = len(nums)
        step = 1
        ptr = True
        for i in range(l-2,-1,-1):
            if nums[i] == 0 or nums[i] < step:
                ptr = False
                step +=1
            else:
                step = 1
                ptr = True
        return ptr