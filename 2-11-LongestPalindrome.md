# 最长回文子串
## [链接](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/)
## 思路 
动态规划，若dp[i+1, i+k-2] == true 并且 s[i] == s[i+k-1]则 dp[i, i+k-1] = true;
## 代码
```c++
  public class Solution {
    public string LongestPalindrome(string s) {
            int len = s.Length;
            if (len <= 1) return s;
            bool[ , ] dp = new bool[len, len];
            int resLeft = 0, resRight = 0;
            for(int i = 1;i<len;i++)
            {
                dp[i,i] = true;
                dp[i,i - 1] = true;

            }
            for(int k = 2;k<=len;k++) {
                for(int i = 0; i <= len - k; i++)
                {
                    if(s[i]==s[i+k-1] && dp[i + 1, i + k - 2])
                    {
                        dp[i,i + k - 1] = true;
                        if(resRight-resLeft+1<k)
                        {
                            resLeft = i;
                            resRight = i + k - 1;
                        }
                    }
                }
            }
            string result = "";
            for(int i=resLeft;i<=resRight;i++)
            {

                result += s[i];
            }

            return result;
    }
}
```