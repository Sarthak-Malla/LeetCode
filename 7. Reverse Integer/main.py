class Solution:
    
    def reverse(self, x: int) -> int:
        
        if (x < 0):
            ans = -1 * int(str(x*-1)[::-1])
        else:
            ans = int(str(x)[::-1])
        
        return ans if ans in range(-2**31, 2**31-1) else 0

if __name__ == "__main__":
    n = -123

    sol = Solution()
    print(sol.reverse(n))