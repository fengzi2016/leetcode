## 题目逆波兰表达式求值

根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

## 思路
- 维护一个栈，遍历数组，当是当前元素数字时入栈，不是数字则2次弹出栈顶元素，并进行计算，将结果push到栈里。
```c++
 bool isFlag(string s){
        if(s == "+" || s == "-" || s == "/" || s == "*") {
            return true;
        }
        return false;
    }
    int stringToNumber(string a) {
        vector<char> s(a.begin(),a.end());
        int k=1;
        int res = 0;
        int end = 0;
        if(a[0]=='-') end = 1;
        for(int i=s.size()-1;i>=end;i--){
            res += (s[i]-'0' )* k;
            k *= 10;
        }
        if(end == 1) res*=-1;
        return res ;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res = 0;
        if(tokens.size()==0) return 0;
        if(tokens.size()==1) return stringToNumber(tokens[0]);
        for(int i=0;i<tokens.size();i++) {
            string cur = tokens[i];
            if(!isFlag(cur)){
                s.push(stringToNumber(cur));
            }else{
                    int right = s.top();
                    s.pop();
    
```