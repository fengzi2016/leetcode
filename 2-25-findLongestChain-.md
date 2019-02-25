# 最长数对链
## [题目链接](https://leetcode-cn.com/problems/maximum-length-of-pair-chain/submissions/)
## 思路
- 动态规划，dp[i]表示下标i能得到的最长数链，先根据第一列排序，再找dp中的最大值
- 贪心算法，先根据第二列排序，只要满足条件就++

### 动态规划
```c++
  class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int row = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> dp(row, 1);
        for(int j = 1; j < row; j++){
            for(int i = 0; i < j; i++){
                if(pairs[j][0] > pairs[i][1]){
                    dp[j] = max(dp[i]+1, dp[j]);
                }
            }
        }
        int ans = 0;
        for( int x : dp){
            ans = max(ans,x);
        }
        return ans;
    }
};
```
### 贪心
```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        int cur = Integer.MIN_VALUE, ans = 0;
        for (int[] pair: pairs) if (cur < pair[0]) {
            cur = pair[1];
            ans++;
        }
        return ans;
    }
}

```