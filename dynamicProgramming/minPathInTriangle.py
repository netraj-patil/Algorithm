class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        arr = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            arr[-1][i] = triangle[-1][i]
        for i in range(n-1,0,-1):
            for j in range(i):
                arr[i-1][j] = min(arr[i][j], arr[i][j+1]) + triangle[i-1][j]
        return arr[0][0]
        