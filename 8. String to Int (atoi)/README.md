# String to Integer (atoi)
<p>
Implement the <code>myAtoi(string s)</code> function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
<br>
The algorithm for <code>myAtoi(string s)</code> is as follows:
<p>
<ol>
<li>Read in and ignore any leading whitespace.
<li>Check if the next character (if not already at the end of the string) is <code>'-'</code> or <code>'+'</code>. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
<li>Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
<li>Convert these digits into an integer (i.e. <code>"123" -> 123, "0032" -> 32</code>). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
<li>If the integer is out of the 32-bit signed integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, then clamp the integer so that it remains in the range. Specifically, integers less than <code>-2<sup>31</sup></code> should be clamped to <code>-2<sup>31</sup></code>, and integers greater than <code>2<sup>31</sup> - 1</code> should be clamped to <code>2<sup>31</sup> - 1</code>.
<li>Return the integer as the final result.
</ol>

<strong>Note:</strong>
<ul>
<li>Only the space character <code>' '</code> is considered a whitespace character.
<li><strong>Do not ignore</strong> any characters other than the leading whitespace or the rest of the string after the digits.
</ul>

### Example 1:
```
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
```

### Example 2:
```
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
```

### Example 3:
```
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
```

### Constraints:
<ul>
<li><code>0 <= s.length <= 200</code>
<li><code>s</code> consists of English letters (lower-case and upper-case), digits <code>(0-9), ' ', '+', '-', and '.'</code>.
</ul>