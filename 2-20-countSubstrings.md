# 回文子串
## [题目链接](https://leetcode-cn.com/problems/palindromic-substrings/)
## 思路
- 遍历字符串 s 时，对每一位字符进行左右扩展，并判断是否为回文串
- 若为回文串则继续向两端扩展
- 否则循环进入下一个字符
- 分为奇数回文串和偶数回文串两种情况

## 代码
```c++
  class Solution {
    public:
     int countSubstrings(string s) {
       int ans = 0, n = s.length();
       for(int center = 0; center <= 2*n -1; center++) {
         int left = center / 2;
         int right = left + center % 2;
         while(left >= 0 && right < n && s[left] == s[right]){
           right ++;
           left --;
           ans ++;
         }
       }
       return ans;
     }
  }
```