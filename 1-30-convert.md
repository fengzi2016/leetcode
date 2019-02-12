## 题目

- [leetcode](https://leetcode-cn.com/problems/zigzag-conversion/solution/)

## 思路

- 一个变量控制向上还是向下的方向，用一个字符串数组进行记录。


##  实现
```c++
string convert(string s, int numRows) {
      if(numRows==1) return s;
      string res;
      int len = min(int(s.size()), numRows);
      vector<string> rows(len);
      bool goDown = false;
      int currRow = 0;
      for(char c:s){
        rows[currRow] += c;
        if(currRow == 0 || currRow == len - 1) goDown = !goDown;
        currRow += goDown? 1 : -1;
      }
      for(string row:rows){
        res += row;
      }
      return res;
    }
```