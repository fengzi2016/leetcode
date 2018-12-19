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
                if(map[i-coins[j]][j]>0){
                   dp[i] = min(dp[i],dp[i-coins[j]]+1);
                   if(dp[i]==dp[i-coins[j]]+1){
                      vector<int> tmp = map[i-coins[j]];
                      tmp[j]--;
                      //不能用insert，因为重复的key会被放弃而不被覆盖
                      map[i] = tmp;
                  }
                }  
              }
          }
          if(!map.count(i)){
              int z[] = {c2,c3,c5};
              vector<int> ones(z,z+3);
              map.insert(make_pair(i,ones));
        }
      }
      return dp[amount]>amount?-1:dp[amount];
  }
vector<int> singer(vector<int> v1,vector<int> v2) {
    vector<int> t;
    vector<int> ans;
    for(int i=0;i<2;i++){
        for(int j=i;j<t.size();j+=2){
            if(t[j+1]>t[j+2]){
                continue;
            }
        }
    }
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};
bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode*> s;
        if(!root) return false;
        if(root->val<=sum) s.push(root);
        int result = 0;
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            result += cur->val;
            cout<<cur->val<<endl;
            if(result==sum&&!cur->left&&!cur->right) return true;
            if(cur->left&&cur->left->val+result<=sum){
              s.push(cur->left);
            }
            if(cur->right&&cur->right->val+result<=sum){
              s.push(cur->right);
            }
        }
        return false;
        
    }

int main(){
   int t1[] = {2,4,6,8,10};
   int t2[] = {3,6,7,9,11};
   // vector<int> coins(t1,t1+3);
   vector<int> vt1(t1,t1+5);
   vector<int> vt2(t2,t2+5);
   int c2 = 1, c3 = 1, c5 = 2;
   int v = 10;
   vector<int> res=singer(vt1,vt2);
   
  // cout<<coinChange2(coins,v,c2,c3,c5);
}
