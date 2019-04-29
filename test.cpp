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

// using namespace std;

// int fn(int n){
//     if(fibs[n]!=-1) {
//       return fibs[n];
//     }else{
//         fibs[n]=fn(n-1)+fn(n-2);
//         return fibs[n];
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     fibs[0] = 0;
//     fibs[1] = 1;
//     cout<<fn(n);
// }

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <math.h>
#include <map>

using namespace std;
vector<int> arr;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int solution() {
    map<int,int> threes;
    int result = 0;
    int i = 2;
    int n = pow(3,i);
    while(n <= pow(10,9)){
          threes[n] = i++;
          n = pow(3,i);
      }
    for(int j = 0; j < arr.size(); j++){
        if(threes.count(arr[j])){
            result += threes[arr[j]];
        }
    }
    return result;

}
/******************************结束写代码******************************/


int main() {
    int res;
	  int n;
    cin >> n;
    for(int i = 0; i < n; i++){
       int tmp;
       cin >> tmp;
       arr.push_back(tmp);
    }
    res = solution();
    cout << res << endl;
    return 0;

}