**题目**
-  岛屿的个数
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1

**思路**
- 维护一个数组visited，遍历给定参数grid的每个元素，并且对visited进行广度搜索和深度搜索来确认哪些1应该是一个岛屿的。或者 把维护一个数组改为将一个岛屿的且已经遍历过的“1”改为“2”；
- 用第一种方法的话数量添加的条件是，grid[i][j]=='1'&&!visited[i][j],因为深度优先和广度优先的结合已经把一个岛屿的其它“1”的visited标识改为了true；
- 用第二种方法的话数量添加的条件是，grid[i][j]=='1'。因为深度优先和广度优先的结合已经把一个岛屿的“1”全改为了“2”；

```c++
    // 方法一
    int numIslands(vector<vector<char>>& grid){
        if(grid.size()==0)return 0;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]=='1') {
                    DFS(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;       
    }
    void DFS(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size() || grid[i][j]!='1' || visited[i][j]) return;
        visited[i][j] = true;
        DFS(grid,visited,i+1,j);
        DFS(grid,visited,i-1,j);
        DFS(grid,visited,i,j-1);
        DFS(grid,visited,i,j+1);
        
    }

```

```c++
// 方法二
    int numIslands(vector<vector<char>>& grid){
        if(grid.size()==0)return 0;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1') {
                    DFS(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;       
    }
    void DFS(vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size() || grid[i][j]!='1') return;
        grid[i][j] = '2';
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j-1);
        DFS(grid,i,j+1);
        
    }
```