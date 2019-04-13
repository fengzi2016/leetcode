#include<iostream>
// #include<cstdio>
#include<algorithm>
// #include<stdio.h>
#include<vector>
#include<stack>
// #include<unordered_map>
// #include<unordered_set>
// #include<numeric> 
// #include<map>
// #include<queue>
using namespace std; 
int main(){
  int n;
  cin >> n;
  vector<int> numbers;
  vector<int> rvnumbers;
  stack<int> sta;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    numbers.push_back(tmp);
   // cout << numbers[i]<<endl;
    sta.push(numbers[i]);
  }

  int count = 0,remember = 1;
  for(int j = 0; j < n - 1; j++){
    if(numbers[j] > numbers[j+1]){
      count+=remember;
      remember = 1;
    }else if(numbers[j] < numbers[j+1]){
      remember++;
    }
  }

  while(!sta.empty()) {
    int cur = sta.top();
    sta.pop();
    rvnumbers.push_back(cur);
  }
  int pre = rvnumbers[0];
  int current,j = 0;
  for(j = 1; j < n; j++){
    current = rvnumbers[j];
    if(current > pre){
      cout<<j<<endl;
      break;
    }
  }
  cout<<j;
  int result = n - j + 1;
 // cout<< result;
}

// int main(){
//   string s;
//   cin>>s;
//   int size  = s.size();
//   if(size == 0) return 0;
//   vector<int> dp(size,0);
//   dp[0] = s[0] == '1' ? 1 : 0;
//   for(int i = 1; i < size; i++){
//     if(s[i] == '1'){
//       dp[i] = dp[i-1] + 1;
//     }
//   }
//   int beforemax = dp[0];
//   for(int j = 1; j<size; j++){
//     if(dp[j]==0){
//       beforemax = dp[j-1];
//       break;
//     }
//   }
//   int firstandend = 0;
//   firstandend = dp[size -1] + beforemax; 
//   sort(dp.begin(),dp.end());
//   int maxlen = dp[size - 1];
//   int max = std::max(firstandend,maxlen);
//   cout<<max;
//  }
