# 思路
- 自己：
```c++

#include <iostream>
#include <cstdio>
#include <algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> dailyTemperatures(vector<int>& temperatures) ;
    
    int arr[] = {
        73,74,75,71,69,72,76,73
    };
    vector<int> exa(arr,arr+8);
    dailyTemperatures(exa);
    
}
 vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        
        vector<int> res;
        if(temperatures.size()==1){res.push_back(0); return res;}
        stack<int> s;
        int k=0;
        for(int i=temperatures.size()-1;i>=0;i--){
            s.push(temperatures[i]);
        }
        int t = 0;
        int cur = s.top();
        s.pop();
        vector<int> ss;
        int first;
        while(!s.empty()) {
            
            t++;
            k++;
            int tmp = s.top();
            if(tmp>cur){
                
                cur = tmp;
                res.push_back(k);
                if(ss.size()) {
                    s.push(tmp);
                    for(int i=k;i>0;i--){
                     s.push(ss[i]);
                    }
                   
                    cur = first;
               
                ss.clear();
                s.pop();
                k=0;
                continue;
                }
                k=0;
            }else {
                if(ss.size()==0){
                    first = tmp;
                }
                ss.push_back(tmp);
               
               
            }
             s.pop();
             if(t>100) break;
            
        }
        if(t!=temperatures.size()) {
            for(int i=0;i<t-temperatures.size();i++){
                res.push_back(0);
            }
        }
        return res;
    }
```
- 别人：
```c++
    class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};
```