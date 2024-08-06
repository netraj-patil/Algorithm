class Solution:
    def stairs(self, n, total,dic):
        if n == 0:
            return 1
        if n<0 or n>total:
            return 0
        if n in dic:
            return dic[n]
        
        a = self.stairs(n-1,total,dic)
        b = self.stairs(n-2,total,dic)
        dic[n] = a+b
        return a+b
        
    def climbStairs(self, n: int) -> int:
        dic = {}
        return self.stairs(n,n,dic)