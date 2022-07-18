class Solution:
    
    def reverse(self, x: int) -> int:

        if x not in range(-2**31, (2**31) - 1):
            return 0

        ans = 0
        s = str(x)
        a = ""
        sign = ""
        
        if (x < 0):
            sign = s[0]
            s = s[1:]
            
        a = sign + s[::-1]
        ans = int(a)
        
        return ans

if __name__ == "__main__":
    n = 1534236469

    sol = Solution()
    print(sol.reverse(n))