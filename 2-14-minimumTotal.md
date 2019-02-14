# 题目 三角形最小路径和
## [题目链接](https://leetcode-cn.com/problems/triangle/submissions/)
## 思路
- 自底向上，将参数数组重新赋值，第i行第j列表示能根据邻居点到达的路径的最小和。
- 第i行j列的最小和为 第i行第j列所在值 + min（第i+1行j列 , 第i+1行j+1列）
- 最后的结果为 第0行0列

## 代码
```c++
  class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size() - 2; i>=0;i--){
          for(int j=0;j<triangle[i].size();j++){
            triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
          }
        }
        return triangle[0][0];
    }
};
```