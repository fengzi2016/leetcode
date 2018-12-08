#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
#include <unordered_map>
#include<unordered_set>
using namespace std;
bool checkInclusion(string s1, string s2) {
       vector<int> ans(26,0);
       for(int i=0;i<s1.length();i++){
           ans[s1[i]-'a']++;
       }
       vector<int> tmp = ans;
       int j;
       for(int i=0;i<s2.length()-s1.length();i++){
           for(j=0;j<s1.length();j++){
               
               if(tmp[s2[i+j]-'a']<=0){
                   break;
               }else{
                   tmp[s2[i+j]-'a']--;
               }
           }
           cout<<j<<endl;
           if(j==s1.length()) return true;
           else {
               tmp = ans;
           }
       }
        return false;
    }
int main(){
   cout<<checkInclusion("ab","222ba");
}
