**题目：**
- 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
**思路：**
- 递归：对于任意子串s1，s2来说，如果从第i个字符处切开，s1得到左边s11,右边s12子字符串，s2得到左边s21,s22子字符串，那么一定满足，s11和s21是扰乱字符串并且s12和s22是扰乱字符串 ，或者s11和s22是扰乱字符串并且s12和s21是扰乱字符串。
- 动态规划：那一个变量来维护不同长度的子字符串的扰乱字符串的结果值，即result[i][j][k]，其中i表示s1的起始下标，j表示s2的起始下标，k表示当前字符串长度，判断规则和递归一样，最后的返回为result[0][0][s1.length()]

```c++
    // 动态规划代码
   class Solution {
    public:
        bool isScramble(string s1, string s2) {
            if(s1.length()!=s2.length()) return false;
            if(s1.length()==1){
                return s1==s2;
            }
            if(s1.length()==0) {
                return true;
            }
            boolean[][][] res = new boolean[s1.length()][s2.length()][s1.length()+1];
            for(int i=0;i<s1.length();i++){
                for(int j=0;j<s2.length();j++) {
                    res[i][j][1] = s1.charAt(i) == s2.charAt(j);
                }
            }
            for(int len=2;len<=s1.length();len++) {
                // 假设s1.length==5 
                //2->6 原串切割后的子串长度
                for(int i=0;i<s1.length()-len+1;i++) {
                    // 0->5-2...6+1 => 0=>4,3,2,1,0
                    // 子串s11起始点从4=>0
                    for(int j=0;j<s2.length()-len+1;j++) {
                        // 0->5-2...6+1 => 0=>4,3,2,1,0
                        // 子串s21的起始点从4=>0
                        
                        for(int k=1;k<len;k++) {
                            
                            // res[i][j][k] => s11~s21
                            // res[i+k][j+k][len-k] => s12~s22
                            // res[i+k][j][len-k] => s12~s21
                            // res[i][j+len-k][k] => s11~s22
                            res[i][j][len]=res[i][j][k]&&res[i+k][j+k][len-k] || res[i+k][j][len-k]&&res[i][j+len-k][k];
                        }
                    }
                }
            }
            return res[0][0][s1.length()];
        }
    };

```
**循环的解释：**
首先按单个字符比较，判断它们之间是否是scrambled的
在更新第二个表中第一个值(gr和rg是否为scrambled的)时，比较了第一个表中的两种构成，一种是 g与r, r与g，另一种是 g与e, r与e，其中前者是真，只要其中一个为真，则将该值赋真。
```c++
     r    g    e
g    x    √    x
r    √    x    x
e    x    x    √


     rg    ge
gr    √    x
re    x    x


     rge
gre   √
```