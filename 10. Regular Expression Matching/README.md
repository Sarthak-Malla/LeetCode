# Regular Expression Matching
<p>
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
<ul>
<li><code>'.'</code> Matches any single character.​​​​
<li><code>'*'</code> Matches zero or more of the preceding element.
</ul>
The matching should cover the entire input string (not partial).
</p>
 
### Example 1:
```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2:
```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

### Example 3:
```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

### Constraints:
<ul>
<li><code>1 <= s.length <= 20</code>
<li><code>1 <= p.length <= 30</code>
<li><code>s</code> contains only lowercase English letters.
<li><code>p</code> contains only lowercase English letters, <code>'.'</code>, and <code>'*'</code>.
<li>It is guaranteed for each appearance of the character <code>'*'</code>, there will be a previous valid character to match.
</ul>