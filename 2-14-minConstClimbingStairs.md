# 使用最小时间爬楼梯
## [题目链接](https://leetcode-cn.com/problems/min-cost-climbing-stairs/comments/)
## 思路
- 动态规划，dp[i] = min(dp[i-1],dp[i-2])+cost[i]
```c++
  int minCostClimbingStairs(vector<int>& cost) {
        int size  = cost.size();
        if(size==0) return 0;
        if(size<=2) return min(cost[0],cost[1]);
        vector<int> dp(size, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<size;i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[size-1],dp[size-2]);
    }
```