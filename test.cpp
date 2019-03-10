#include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<stdio.h>
#include<vector>
// #include<stack>
// #include<unordered_map>
// #include<unordered_set>
// #include<numeric> 
// #include<map>
// #include<queue>
using namespace std; 

 int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        int count = 0;
        int max = INT_MIN;
        for(int i = 0, j ; i < n - 1; i++){
            int pre = nums[i];
            for(j = i+1; j < n; j++){
                if(nums[j]>=pre){
                    pre = nums[j];
                    dp[i][j] = dp[i][j - 1] + 1;
                }else{
                    dp[i][j] = dp[i][j - 1];
                }
                if(dp[i][j] > max){
                  max = dp[i][j];
                  count = 1;
                }else if(dp[i][j] == max){
                  count++;
                }
            } 
        }
        return count;
    }
int main(){
  int a[] = {1,3,5,4,7};
  vector<int> v(begin(a),end(a));
  cout<<findNumberOfLIS(v);
}
