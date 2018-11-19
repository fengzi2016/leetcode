**想法**
- 两个stack，一个用来保存个数，一个用来保存字符串，遍历字符串，如果遇到数字，我们更新计数变量cnt；如果遇到左中括号，我们把当前cnt压入数字栈中，把当前t压入字符串栈中；如果遇到右中括号，取出数字栈中顶元素，存入变量k，然后给字符串栈的顶元素循环加上k个字符串，然后取出顶元素存入字符串t中；如果遇到字母，我们直接加入字符串t。

```c++
   class Solution {
public:
    string decodeString(string s) {
        string res = "", t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0; t.clear();
            } else if (s[i] == ']') {
                int k = s_num.top(); s_num.pop();
                for (int j = 0; j < k; ++j) s_str.top() += t;
                t = s_str.top(); s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};
```