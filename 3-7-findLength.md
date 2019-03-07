# 最长重复子数组
## [题目链接](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/submissions/)
## 思路
- 动态规划，从后往前
- dp[i][j]表示A[i:]和B[j:]之间最长重复子数组数量
## 代码
```c++
  class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = max(A.size(),B.size());
        int ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        for(int i = A.size() - 1; i >= 0; i--){
            for(int j = B.size() - 1; j >= 0; j--){
                if(A[i]==B[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }
                if(dp[i][j]>ans){
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};
```