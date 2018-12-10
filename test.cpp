#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
#include <unordered_map>
#include<unordered_set>
using namespace std;
int coinChange2(vector<int>& coins, int amount, int c2, int c3, int c5){
      vector<int> dp(amount+1,amount+1);
      unordered_map<int,vector<int> > map;
      int n[] = {c2,c3,c5};
      vector<int> nums(n,n+3);
      map.insert(make_pair(0,nums));
      dp[0] = 0;
      for(int i=1;i<=amount;i++){
          for(int j=0;j<coins.size();j++){
              if(i>=coins[j]){
                cout<<map[i-coins[j]][j]<<endl;
                if(map[i-coins[j]][j]>0){
                //    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                //    if(dp[i]==dp[i-coins[j]]+1){
                //       vector<int> tmp = map[i-coins[j]];
                //       tmp[j]--;
                //       map.insert(make_pair(i,tmp));
                //   }
                }  
              }
          }
      }
      return dp[amount]>amount?-1:dp[amount];
  }
int main(){
   int t[] = {2,3,5};
   vector<int> coins(t,t+3);
   int c2 = 1, c3 = 1, c5 = 1;
   int v = 10;
   cout<<coinChange2(coins,v,c2,c3,c5);
}
