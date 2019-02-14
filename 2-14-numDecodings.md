# 解码方法
## [题目链接](https://leetcode-cn.com/problems/decode-ways/submissions/)
## 思路
- s字符串前i个字的总解法为前i-2 + 前 i-1 的总解法之和。
- 因为前i-1可能不和第i-2个字能融合为一个解法，比如i-1为7 i-2为2
- 所以f(n) =  f(n-1) + f(n-2) 其中s[n-1] 和 s[n-2]都要不为0 且s[n-2]s[n-1] < 27

## 代码
```c++
  class Solution {
    public:
    int numDecodings(string s) {
      if(s.empty()) return 0;
      vector<int> v(s.size()+1);
      v[0] = 1;
      v[1] = s[0] == '0' ? 0 : v[0];
      for(int i=2; i<s.size()+1; i++) {
        v[i] = (s[i-1] == '0' ? 0 : v[i-1]) + (s[i-2] == '1' ? v[i-2] : s[i-2]=='2'&&s[i-1]<='6' ? v[i-2] : 0);
      }
      return v[s.size()];
    }
};
```