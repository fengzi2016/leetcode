**问题**
-
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
**思路**
- 维护一个栈sta，对参数s进行遍历，第一次栈里只有s[0]，如果sta.top()和s[i+1]是匹配括号，则弹出sta.top(),否则压入栈。如果弹出后栈为空，则下一次遍历直接压入。

```c++
bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char> sta;
        if(s[0]){
             sta.push(s[0]);
        }
        else return true;
        for(int i=1;i<s.length();i++) {
            if(!sta.empty()){
                     auto tmp = sta.top();

                if(tmp == '(' && s[i] == ')') {
                    sta.pop();
                }
                else if(tmp == '[' && s[i] == ']') {
                    sta.pop();
                }
                else if(tmp == '{' && s[i] == '}') {
                    sta.pop();
                }else {
                     sta.push(s[i]);
                }
            }else {
                sta.push(s[i]);
            }
           
        }
        if(sta.empty()) return true;
        return false;
    }
```