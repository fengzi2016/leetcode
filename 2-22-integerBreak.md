# 整数拆分
## [题目链接](https://leetcode-cn.com/problems/integer-break/submissions/)
## 思路
- 动态规划，dp[i]表示i所可以得到的最大乘积
- dp[i] = max(dp[i],max(j*(i-j), j*dp[i-j]));
## 代码
```c++
  class Solution {
public:
    int integerBreak(int n) {
        if(n<2||n>58) return 0;
        // dp[i]表示i可以获得的最大乘积
        vector<int> dp(n+1,0);
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
```