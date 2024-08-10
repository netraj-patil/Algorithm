class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        table = [[0 for x in range(n)] for y
             in range(n)]
        
        i = 0
        m = 1
        start = 0

        while i<n:
            table[i][i]=1
            i+=1
        
        i = 0
        while i<n-1: 
            if s[i] == s[i+1]:
                table[i][i+1] = 1
                if m <2:
                    start = i
                    m = 2
            i+=1
        
        k = 3
        while k<= n:
            i = 0
            while i < n-k+1:
                j = i+k-1
                if s[i]==s[j] and table[i+1][j-1]:
                    table[i][j] = 1
                    if k > m:
                        start = i
                        m = k
                i+=1
            k+=1
        return s[start:start+m]