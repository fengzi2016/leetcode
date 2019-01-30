#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
#include <unordered_map>
#include<unordered_set>
#include <numeric> 
using namespace std; 
 string convert(string s, int numRows) {
      if(numRows==1) return s;
      string res;
      int len = min(s.length(),numRows);
      vector<string> rows(len);
      bool goDown = true;
      int currRow = 0;
      for(int i=0;i<s.length();i++){
        rows[currRow] += s;
        if(currRow == 0 || currRow == len - 1) goDown = !goDown;
        currRow += goDown? 1 : -1;
      }
      for(string row:rows){
        res += row;
      }
      return res;
 }
int main(){
  string tmp = "LEETCODEISHIRING";
  int numRows = 4;
  cout<<convert(tmp,numRows)<<endl;
}
