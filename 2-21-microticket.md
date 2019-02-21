# 最低票价
## [题目链接]()https://leetcode-cn.com/problems/minimum-cost-for-tickets/submissions/
## 思路
- 动态规划+递归
- dp(i)表示从第i个下标到最后一个元素所需要的最少票价
- i 每次循环加 1， 
  - 当第 i 天会旅游时： **d([i) = min(dp(i+1)+costs[0],min(dp(i+7)+costs[1],dp(i+30)+costs[2]));**
  - 当第i天不会旅游时： dp[i] = dp[i+1];
- 维护一个记忆性数组记录已经计算过的下标数
## 代码
```c++
class Solution {
public:
    set<int> dayset;
    vector<int> memo;
    vector<int> _costs;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto day: days){
            dayset.insert(day);
        }
        memo.reserve(366);
        for(int i=0;i<366;i++){
            memo[i] = -1;
        }
        _costs = costs;
        return dp(1);
    }
    int dp(int i){
        if(i > 365){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int ans;
        if(dayset.count(i)){
            ans = min(dp(i+1)+_costs[0],dp(i+7)+_costs[1]);
            ans = min(ans, dp(i+30)+_costs[2]);
        }else{
            ans = dp(i+1);
        }
        memo[i] = ans;
        return ans;
    }
};
```