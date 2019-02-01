## 根据字符出现频率排序
### [题目链接](https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/237/learn-to-use-dict/989/)
### 思路
用map记录,用priority_queue排序
### 实现
```c++
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
```
