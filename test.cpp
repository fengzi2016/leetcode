#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;
int dfs(vector<vector<int> >& matrix,int i,int j){
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())return 0;
        return min((dfs(matrix,i+1,j),dfs(matrix,i,j+1)),(dfs(matrix,i-1,j),dfs(matrix,i,j-1)))+1;
}
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > res(m,vector<int>(n,0));
        res[0][0] = matrix[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              res[i][j] = dfs(matrix,i,j);
            }
        }
        return res;
    }
int main(){
   vector<vector<int> > s(3,vector<int>(3,0));
   s[2][2] = 1;
   updateMatrix(s);
}
