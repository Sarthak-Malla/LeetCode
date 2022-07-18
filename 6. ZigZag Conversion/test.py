class Solution:
    def __init__(self) -> None:
        pass

    def convert(self, s: str, numRows: int) -> str:
        r = 0
        flip = False
        ans = ""

        mat = [[] for _ in range(numRows)]

        for char in s:
            mat[r].append(char)

            if (r == numRows - 1):
                flip = True
            elif (r == 0):
                flip = False
            
            if (flip):
                if (r > 0):
                    r -= 1
            else:
                r += 1
        
        for rows in mat:
            for columns in rows:
                ans += columns

        return ans


if __name__ == "__main__":
    s = "ABC"
    n = 1

    sol = Solution()
    ans = sol.convert(s, n)

    print(ans)
