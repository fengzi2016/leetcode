// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
// 思路：动态规划，新建一个数组存储到达每个元素的最小路径值，通过dp[i-1][j],dp[i][j-1]最小值来确认
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size() , n = grid[0].size();
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int i=1;i<n;i++) dp[0][i] = dp[0][i-1] + grid[0][i];
    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}