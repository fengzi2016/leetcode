# 求柱状图中最大的矩形
## 思路：
- 欸其实连基本思路都没有想到呢，我一直觉得有灵活的思路，却不去想基本方法。
- 一般人的基本思路是用两个for循环从左往右把所有的矩形面积求出来，再取最大，这样的复杂度是O(n*n)
- 大神思路：维护一个栈，栈里面是一个按照参数数组顺序遍历而形成的下标递增序列，当遍历参数数组时，
    - 如果当前元素小于栈顶元素（下标）所对应的元素则栈顶元素出栈，并且求出面积，和maxArea进行比较，更新maxArea
    - 如果当前元素大于等于栈顶元素（下标）所对应的元素则将当前元素下标压进栈
    - 当遍历完一遍后，还要考虑栈是否已经清空，如果没有则要把每个元素弹出，并且在弹出时计算面积，i==n不变，更新maxArea

注意：在计算面积时，要考虑到栈是否已经为空。

代码：
```c++
    int largetsRectangleArea(vector<int>& hist){
        int maxArea = 0,n=hist.size(),i=0;
        vector<int> store=hist;
        stack<int> s;
        while(i<n) {
            if(s.empty()||store[s.top()]<=store[i]){
                s.push(i++);
            }else{
                int t = s.top();
                s.pop();
                maxArea=max(maxArea,store[t]*(s.empty()?i:i-s.top()-1));
            }
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            maxArea=max(maxArea,store[t]*(s.empty()?i:i-s.top()-1));
        }
    return maxArea;
    }
```