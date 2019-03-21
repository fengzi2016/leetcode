# 不含AAA或BBB的字符串
## [题目🔗](https://leetcode-cn.com/problems/string-without-aaa-or-bbb/)
## 思路
- 贪心算法
- 先构造最长公共子序列，比如'abb'
- 对于每次循环，如果满足倒数第一和倒数第二相等并且等于b，则这一次应该加a 。如果不相等则有两种可能，1.需要加b，2. A比B大，b已经用完，所以加上剩下的a
## 代码
```c++
  class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s = "";
        if(A==0&&B==0) return s;
        while(A||B){
           bool writeA = false;
           int size = s.length();
           if(size>=2&&s[size-1]==s[size-2]){
             if(s[size-1]=='b') writeA = true;
           }else if(A>=B){
             writeA = true;
           }
           if(writeA){A--;s+='a';}
            else{B--; s+='b';}
        }
        return s;
    }
};
```