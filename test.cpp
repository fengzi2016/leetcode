#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<numeric> 
#include<map>
#include<queue>
using namespace std; 
struct info {
  char c;
  int number;
  bool operator < (const info &a) const
  {
   return a.number > number;
  }
};
 string frequencySort(string s) {
        if(s.length()<=2) return s;
        map<char,int> strMap;
        for(int i = 0; i < s.length(); i++){
            if(strMap.count(s[i])){
                strMap[s[i]] ++;
            }else{
                strMap.insert(pair<char,int>(s[i],1));
            }
        }
        string ret = "";
        priority_queue<info> pq;
        for(map<char,int>::iterator it = strMap.begin(); it!=strMap.end(); it++){
          info tmp;
          tmp.c = it -> first;
          tmp.number = it -> second;
          pq.push(tmp);
        }
        while(!pq.empty()){
          info cur = pq.top();
          pq.pop();
          int len = cur.number;
          char c = cur.c;
          while(len) {
            ret += c;
            len -- ;
          }
        }
        return ret;
    }
   int minCostClimbingStairs(vector<int>& cost) {
        int size  = cost.size();
        if(size==0) return 0;
        if(size<=2) return min(cost[0],cost[1]);
        vector<int> dp(size, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<size;i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[size-1],dp[size-2]);
    }
   bool isDengCha(vector<int>& subA) {
        cout<<"size:"<<subA.size()<<endl;
        if(subA.size()<3) return false;
        int cha = subA[1] - subA[0];
        cout<<"子序列"<<endl;
        cout<<subA[0]<<subA[1];
        for(int i=2;i<subA.size();i++){
            cout<<subA[i];
            if(subA[i]-subA[i-1]!=cha){
                return false;
            }
        }
        return true;
    }
 int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        vector<int>::iterator it;
        it=A.begin();
        vector<vector<int> > dp(size,vector<int>(size,0));
        for(int i = 0; i < size; i++){
            for(int j = i+1; j< size; j++){
                vector<int> tmp;
                tmp.assign(it+i,it+j+1);
                if(isDengCha(tmp)){
                    dp[i][j] = dp[i][j-1] + 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
                tmp.clear();
            }
        }
        return dp[0][size-1] + 1;
        // dp[i,j]表示从i到j的子等差数组的数量
        // 如果i-1 到 i是等差，则dp[i-1,j] = dp[i,j] + 1
        // 如果i 到 j+1 是等差，则dp[i, j+1] = dp[i,j] + 1
        // 否则 dp[i-1,j] = dp[i,j+1] = dp[i,j];
    }
   
int main(){
  int a[] = {1,2,3};
  vector<int> v(begin(a),end(a));
  cout<<numberOfArithmeticSlices(v);
}
