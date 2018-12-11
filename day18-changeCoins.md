# 题目
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11

输出: 3 

解释: 11 = 5 + 5 + 1

# 思路
动态规划，维护一个数组dp，dp[i]代表最少可以用dp[i]个硬币组合成i,假设。其中dp[0] = 0;

假设总和为amout,可选硬币数组为coins,则状态转移方程为：dp[i] = min(dp[i],dp[i-coins[j]]+1);

最后返回的时候要判断是否为-1，即dp[i]仍为初始值

```c++
  int coinChange(vector<int>& coins, int amount){
      vector<int> dp(amount+1,amount+1);
      dp[0] = 0;
      for(int i=1;i<=amount;i++){
          for(int j=0;j<coins.size();j++){
              if(i>=coins[j]){
                  dp[i] = min(dp[i],dp[i-coins[j]]+1);
              }
          }
      }
      return dp[amount]>amount?-1:dp[amount];
  }
```

# 今日头条笔试第一题

升级版changeCoins

## 题目

与上一题的区别是coins数量有限制，面值固定为2，3，5，数量限制为C1，C2，C3

## 思路

- 在上题的基础上维护一个hash **<int,vector<int> >**，element->first表示遍历的数，element->second表示这个数用完硬币后剩下的硬币数量的数组nums，其中nums[0],nums[1],nums[2]分别为c2,c3,c5。
- 因为不是所有的数都可以被硬币组成，所以在每次遍历结尾要判断是否存入hash表，如果不能则插入原始值。



```c++
 int coinChange2(vector<int>& coins, int amount, int c2, int c3, int c5){
     // 初始化size为amount+1，每个元素为amount+1的dp数组
      vector<int> dp(amount+1,amount+1);
      // 声明hash表，unordered_map比map性能更好
      unordered_map<int,vector<int> > map;
      int n[] = {c2,c3,c5};
      vector<int> nums(n,n+3);
      // 将以0为key的值插入hash表
      map.insert(make_pair(0,nums));
      dp[0] = 0;
      for(int i=1;i<=amount;i++){
          // 遍历硬币面值
          for(int j=0;j<coins.size();j++){
              //保证面值比i小
              if(i>=coins[j]){
                if(map[i-coins[j]][j]>0){
                    // 保证还有足够的硬币
                   dp[i] = min(dp[i],dp[i-coins[j]]+1);
                   // 更新hash与i对应的值数组的值
                   if(dp[i]==dp[i-coins[j]]+1){
                      vector<int> tmp = map[i-coins[j]];
                      tmp[j]--;
                      //不能用insert，因为重复的key会被放弃而不被覆盖
                      map[i] = tmp;
                  }
                }  
              }
          }
          // 比如i=1这种不能被组成的，就需要插入原数量数组nums
          if(!map.count(i)){
              int z[] = {c2,c3,c5};
              vector<int> ones(z,z+3);
              map.insert(make_pair(i,ones));
        }
      }
      return dp[amount]>amount?-1:dp[amount];
  }

```





