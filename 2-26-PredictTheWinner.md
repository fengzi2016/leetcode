# 预测玩家
## [题目链接](https://leetcode-cn.com/problems/predict-the-winner/)
## 思路
- 动态规划，dp[i][j]表示从第i到j的子数组中玩家1比玩家2多得了多少分。
- 状态转移方程： dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
## 代码
```c++
  class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for(int s = n; s >= 0; s--){
            for(int e = s+1; e < n; e++){
                int a = nums[s] - dp[s+1][e];
                int b = nums[e] - dp[s][e-1];
                dp[s][e] = max(a,b);
            }
        }
          return dp[0][n - 1] >= 0;
    }
};
```