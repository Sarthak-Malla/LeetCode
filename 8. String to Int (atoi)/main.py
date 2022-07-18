class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if (len(s) <= 0):
            return 0
        
        neg = 1
        if (s[0] == '-'):
            neg = -1
        
        if (s[0] == '-' or s[0] == '+'):
            s = s[1:]
        
        ans = ""
        for char in s:
            if (char.isdigit()):
                ans += char
            else:
                break
        if ans == "":
            return 0
        
        a = neg*int(ans)
                
        if a <= -2**31:
            return -2**31
        elif a >= 2**31 - 1:
            return 2**31 - 1
        else:
            return a

if __name__ == "__main__":
    s = "+1"

    sol = Solution()
    print(sol.myAtoi(s))