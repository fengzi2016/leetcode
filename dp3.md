**题目**
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

**思路**

1. 将这个图当作直方图，每行作为一个直方，得到每行的高，再用largestRectangleArea来计算
2. 一行一行往下找，当n-1行为最大时，第n行一定为最大。假设record[i][0], record[i][1], record[i][2]分别表示当前行第i列所能形成的最大面积的矩阵的左边界、右边界和高。
每遍历完一行:
> 对于第i行第k列元素为1的点，我们可以假设它在本行所形成的左边界为left，右边界为right，则在更新record[k][]数组时，左边界取left和record[k][0]大者，右边界取right和record[k][1]小者，高度取record[k][2]+1。然后根据新的record计算面积，如果更大则更新ans。
[参考链接](https://blog.csdn.net/CristianoJason/article/details/52436342)
3. 动态规划的方法，但是没有图，还没看懂

**解题**
1.
```c++
   int largetsRectangleArea(vector<int>& hist){
        int maxArea = 0,n=hist.size(),i=0;
        vector<int> store=hist;
        stack<int> s;
        while(i<n) {
            if(s.empty()||store[s.top()]<=store[i]){
                s.push(i++);
            }else{
                int t = s.top();
                s.pop();
                maxArea=max(maxArea,store[t]*(s.empty()?i:i-s.top()-1));
            }
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            maxArea=max(maxArea,store[t]*(s.empty()?i:i-s.top()-1));
        }
    return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      int row = matrix.size();
      if(row==0) return 0;
      int col=matrix[0].size();
      if(col==0) return 0;
      int maxArea = 0;
      for(int i=0;i<row;i++) {
        // 每一行维护一个数组来保存前几行的高度
        vector<int> heights(col,0);
        for(int j=0;j<col;j++) {
          int temp = i;
          while(temp>=0&&matrix[temp--][j]=='1') heights[j]++;
        }
        maxArea = max(largetsRectangleArea(heights),maxArea);
      }
      return maxArea;
    }
```
