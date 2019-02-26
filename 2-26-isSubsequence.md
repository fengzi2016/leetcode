# 判断子序列
## [题目链接](https://leetcode-cn.com/problems/is-subsequence/)
## 思路
- 双指针法
- 如果s[i] == t[j] ,i++ 否则j++
## 代码
```c++
  class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};
```