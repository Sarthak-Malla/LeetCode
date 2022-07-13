# Minimum Insertions to Balance a Parentheses String
<p>
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

<ul>
<li>Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
<li>Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
</ul>

In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

<ul>
<li>For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
</ul>

You can insert the characters '(' and ')' at any position of the string to balance it if needed.
<br>
Return the minimum number of insertions needed to make s balanced.
</p>
 

### Example 1:
```
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
```

### Example 2:
```
Input: s = "())"
Output: 0
Explanation: The string is already balanced.
```

### Example 3:
```
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
``` 

### Constraints:

<ul>
<li>1 <= s.length <= 105
<li>s consists of '(' and ')' only.
</ul>