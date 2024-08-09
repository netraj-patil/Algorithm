class Solution:
    def generate(self, n: int) -> List[List[int]]:
        if n == 1:
            return [[1]]
        
        lis = []

        for i in range(n):
            lis2 = []
            for j in range(i + 1):
                if j == 0 or j == i:
                    lis2.append(1)
                else:
                    lis2.append(lis[i-1][j] + lis[i-1][j-1])
            lis.append(lis2)
        
        return lis