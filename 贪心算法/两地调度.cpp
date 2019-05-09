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
class Solution {
public:
    int twoCitySchedCost(vector<vector<int> >& costs) {
        int row = costs.size();
        if (row == 0) return 0;
        int TOA = 0, TOB = 1;
        int aTotal = 0 , bTotal = 0;
        int n = (row+1) / 2;
        int toBNumber = 0, toANumber = 0;
        int r = 0;
        for(; r < row; r++){
            int nextATotal = aTotal + costs[r][TOA];
            int nextBTotal = bTotal + costs[r][TOB];
            if(nextATotal > nextBTotal) {
              bTotal = nextBTotal;
              toBNumber++;
            }else{
              aTotal = nextATotal;
              toANumber++;
            }
            cout<<nextATotal<<endl;
            if(n == toANumber || n == toBNumber) break;
            
        }
        
        if(r<row){
          if(toANumber < toBNumber) {
            while(r<row){
              r++;
              aTotal += costs[r][TOA];
            }
          } else {
             while(r<row){
              r++;
              bTotal += costs[r][TOB];
            }
          }
        }
        return aTotal+bTotal;
    }
};

int main() {
  vector<vector<int> > costs = {
    {10,20},
    {30,200},
    {400,50},
    {30,20}
    };
 
  Solution solution ;
  cout << solution.twoCitySchedCost(costs);
}
