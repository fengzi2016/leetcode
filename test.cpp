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
int main(){
  string tmp = "Aabb";
  cout<<frequencySort(tmp)<<endl;
}
