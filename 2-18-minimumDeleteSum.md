# 两个字符串的最小ASCII删除和
## [题目链接](https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/submissions/)
## 思路
- 维护一个二维向量dp,dp[i][j] 表示s1[i:] s2[j:]所得到的最小ASCII删除和
- dp[i][s2.length()]= dp[i+1][s2.length()] + int(s1[i]);
- dp[s1.length()][j] = dp[s1.length()][j+1] + sint(s2[j]);
- 如果s1[i] == s2[j] 则dp[i][j] = dp[i+1][j+1]（不用删除）
- 如果s1[i] != s2[j] 则dp[i][j] = min(dp[i+1][j])+int(s1[i]),dp[i][j+1]+int(s2[j]));

## 代码
```c++
  class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int> > dp (s1.size()+1,vector(s2.size()+1,0));
        for(int i = s1.size() - 1; i >= 0; i--){
            dp[i][s2.size()] = dp[i+1][s2.size()] + int(s1[i]);
        }
        for(int j = s2.size() - 1; j >= 0; j--){
            dp[s1.size()][j] = dp[s1.size()][j+1] + int(s2[j]);
        }
        for(int i = s1.size() - 1; i >= 0; i--){
            for(int j = s2.size() - 1; j >= 0; j--){
                    if(s1[i] == s2[j]){
                        dp[i][j] = dp[i+1][j+1];
                    } else {
                        dp[i][j] = min(dp[i+1][j] + int(s1[i]),
                                           dp[i][j+1] + int(s2[j]));
                    }
            }
        }
        return dp[0][0];
    }
};
```