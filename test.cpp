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

using namespace std; 
vector< vector< vector<int> > > visited(n,vector<vector<int>>(n,vector<int>(n，-1)));
int main() {
  int n;
  vector<int> x(n*n*n,0);
  vector<int> y(n*n*n,0);
  vector<int> z(n*n*n,0);
  int maxp = 0;
  int maxx,maxy,maxz;

  for(int i = 0; i < n*n*n; i++) {
    for(int j=0; j<4; j++){
      int xp, yp, zp, pp;
      cin << xp << yp << zp << pp;
      x[xp] = xp;
      y[yp] = yp;
      z[zp] = zp;
      visited[xp][yp][zp] = pp;
      if(pp > maxp) {
        maxx = xp;
        maxy = yp;
        
        maxp = pp;
      }
    }
  }
}
