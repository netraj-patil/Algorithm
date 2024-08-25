'''
Container with most water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.'''


class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) -1
        
        m = 0
        while i < j:
            a = min(height[i],height[j]) * (j-i)
            if a> m:
                m = a
            if height[i] > height[j]:
                j -= 1
            else:
                i+=1
        
        return m