# Container With Most Water
<p>
You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0</code> and <code>(i, height[i])</code>.
<br>
Find two lines that together with the x-axis form a container, such that the container contains the most water.
<br>
Return the maximum amount of water a container can store.
<br>
Notice that you may not slant the container.
</p>

### Example 1:
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

### Example 2:
```
Input: height = [1,1]
Output: 1
```

### Constraints:
<ul>
<li><code>n == height.length</code>
<li><code>2 <= n <= 105</code>
<li><code>0 <= height[i] <= 104</code>
</ul>