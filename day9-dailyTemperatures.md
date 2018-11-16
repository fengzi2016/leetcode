## 题目
### 每日温度
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。

## 思路
- 自己：维护一个栈，栈顶是数组最后一个元素，栈底是数组第一个元素， 用一个变量A临时保存当前需要比较的值，再不断出栈比较并用k记录，如果找到比A大的值则将k放在结果中。之后在将之前pop出的比较元素再push回去。
```c++
// 代码没通过，出错
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
- 别人：维护一个递减栈，栈顶最大，栈底最小。for 循环遍历数组，每次都要将当前元素的下标push到栈中；为了维持栈顶元素最大，如果当前需要push的元素比栈顶元素小，则将栈顶元素弹出，直到栈顶元素最大为止，此时当前栈顶元素下标与遍历的下标的差就是所求的天数。

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