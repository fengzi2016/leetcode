# 买卖股票的最佳时机含手续费
## [题目链接](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
## 思路
- 动态规划
- cash代表买入与不买入
- hold代表卖出与不卖出
- cash 初始化为 0， hold 初始化为 -prices[0];
- cash = max(cash, hold + prices[i] - fee);
- hold = max(cash - prices[i], hold); 

### 代码
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0 , hold = -prices[0];
        for(int i = 0; i < prices.size(); i++){
            cash = max(cash, hold + prices[i] - fee);
            hold = max(cash - prices[i], hold);
        }
        return cash;
    }
};
```