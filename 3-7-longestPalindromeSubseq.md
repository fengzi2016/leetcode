# 最长回文子序列
## [题目链接](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)
## 思路
- 动态规划，dp[i][j]表示下标第i到第j的最长回文子序列长度,从中间向两边散开
- 如果s[i] == s[j] 则 dp[i][j] = dp[i+1][j-1]+2;
- 否则dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
## 代码
```c++
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int len = s.length();
      vector<vector<int>> dp(len+1,vector<int>(len,0));
      for(int i = len - 1; i >= 0; i--){
          dp[i][i] = 1;
          for(int j = i+1; j < len; j++){
              if(s[i]==s[j]){
                  dp[i][j] = dp[i+1][j-1]+2;
              }else{
                  dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
              }
          }
      }
        return dp[0][len-1];
    }
};
```