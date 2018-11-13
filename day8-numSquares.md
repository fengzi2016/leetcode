**题目**
- 完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4

**思路**
- 我的：广度优先，队列的元素是所有小于sqrt(n)的完全平方数累加。每次都需要遍历所有小于n的平方根的完全平方数进行累加，结果导致超时。
```js
int numSquares(int n) {
        vector<int> a;
        if(sqrt(n)==int(sqrt(n))) return 1;
        queue<int> q;
        for(int i = 1; i <= sqrt(n) ; i++){
          a.push_back(pow(i,2));
          q.push(pow(i,2));
          
        }   
        int step = 0;
        while(!q.empty()){
            step ++;
            int size = q.size();
            for(int i=0;i<size;i++) {
                int cur = q.front();
                if(cur==n) return step;
                if(cur>n){q.pop();}
                if(cur<n){
                    for(int j=0;j<a.size();j++){
                        int sum = cur+a[j];
                        if( sum <= n ){
                            q.push(sum);  
                        } else {
                        	break;
                        }
                        
                    }
                }
                q.pop();
            }
        }
    }
```
- 别人的：动态规划。每个非完全平方数，可以当作是一个完全平方数+一个普通数。所以可以维持一个n+1的数组dp，dp[i]代表达到i最少需要的完全平方数数量。关键的转移方程为:dp[i+j * j] = min(dp[i+j * j],dp[i]+1); 意思是如果这个元素是完全平方数则取dp[i+j*j]，否则取dp[i]+1。这个动态规划的子问题的范围是两个相邻完全平方数之间的数。

![图片](https://img-blog.csdn.net/20160604170107528?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

```c++
 int numSquares(int n){
     vector<int> dp(n+1,INT_MAX);
     dp[0] = 0;
     for(int i=0;i<n;i++){
         for(int j=1;i+j*j<=n;j++){
             dp[i+j*j] = min(dp[i+j*j],dp[i]+1);
         }
     }
     return dp[n];
 }
```


