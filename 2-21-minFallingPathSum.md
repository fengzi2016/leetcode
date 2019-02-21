# 下降路径最小和
## [题目链接](https://leetcode-cn.com/problems/minimum-falling-path-sum/submissions/)
## 思路
- 动态规划
- 在原始参数的二维vector A上进行修改，A[r][c]表示从最后一行向上相加每列能得到的最小值
- 自底向上，先下面的，由下一行得出上一行，A[r][c] += min(dp[r+1][c-1],dp[r+1][c],dp[r+1][c+1]);
- 注意判断边界条件
## 代码
```c++
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& A) {
      int n = A.size();
      for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < n; j++){
          int best = A[i+1][j];
          if( j > 0) {
            best = min(best, A[i+1][j-1]);
          }
          if( j+1 < n){
            best = min(best, A[i+1][j+1]);
          }
          A[i][j] += best;
        }
      }
      int ans = A[0][0];
      for(int x = 0; x < n; x++){
        ans = min(ans, A[0][x]);
      }
      return ans;
    }
};

```