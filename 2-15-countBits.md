# 比特位计数
## [题目链接](https://leetcode-cn.com/problems/counting-bits/comments/)
## 思路
- 动态规划
- 后一个数和前一个数有关，后一个数1的个数等于前一个数的个数加1
- 如果后一数的因子中有2的n次幂，则1的个数要减去这个n
## 代码
```c++
  class Solution {
    public:
        vector<int> countBits(int num) {
          vector<int> dp(num+1,0);
          for(int i=1;i<=num;i++){
            int count = dp[i-1]+1;
            int current_num = i;
            while(current_num%2==0 && current_num>0){
              current_num /= 2;
              count --;
            }
            dp[i] = count;
          }
          return dp;
        }
};
```