kmp 算法是用来查找子串的位置的。

它记录了一个数组next，
next存储了已经匹配好的原串前N个字符的最长相同前后缀的长度。

设原串为S，子串为M
判断条件是：
- 当S[i] == M[j] 时 next[i] = next[i-1]+1
- 当S[i] !== M[j] 时，递归查询更短的最长相同前后缀


[参考链接](https://blog.csdn.net/v_july_v/article/details/7041827)