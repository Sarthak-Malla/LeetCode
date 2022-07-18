# ZigZag Conversion
<p>
s like this: (you may want to display this pattern in a fixed font for better legibility)
<br>
<code>
P   A   H   N <br>
A P L S I I G <br>
Y   I   R
</code>
<br>
And then read line by line: "PAHNAPLSIIGYIR"
<br>
Write the code that will take a string and make this conversion given a number of rows:
<br>
<code>
string convert(string s, int numRows);
</code>
</p>

### Example 1:
```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

### Example 2:
```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

### Example 3:
```
Input: s = "A", numRows = 1
Output: "A"
```

### Constraints:
<ul>
<li><code>1 <= s.length <= 1000</code>
<li><code>s consists of English letters (lower-case and upper-case), ',' and '.'.</code>
<li><code>1 <= numRows <= 1000</code>
</ul>