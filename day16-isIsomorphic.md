**题目**

同构字符串

给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"

输出: true

示例 2:

输入: s = "foo", t = "bar"

输出: false


**思路**

- 两个unordered_map,结构分别为[s[i],t[i]],[t[i],s[i]],遍历时先判断当前的t[i]是否已经被对应，如果对应了则判断是否与之前的相等，是就跳过，否就返回false；

```c++
    class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> hashMap;
        unordered_map<char,char> memoryMap;
        for(int i=0;i<s.length();i++) {
            if(!memoryMap.count(t[i])) {
                memoryMap[t[i]] = s[i];
            }
             if(memoryMap[t[i]]!=s[i]){
                 return false;
             }
                hashMap[s[i]] = t[i];   
        }
        for(int j=0;j<s.length();j++) {
            if( hashMap[s[j]] != t[j]) 
                return false;
        }
        return true;
        
    }
};
```