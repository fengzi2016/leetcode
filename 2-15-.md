
# 等差数列划分
## [题目链接](https://leetcode-cn.com/problems/arithmetic-slices/submissions/)
## 思路
- 维护当前差d1，当前子等差序列数量dp，下一个差d2，总量这几个变量
- vector从左往右，计算相差值，如果一样则 dp++, 如果不一样 d1=d2;
## 代码
```c++
  class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if(size<=2) return 0;
        int dp=0,sum=0,d1=A[1]-A[0];
        for(int i=2;i<size;++i){
            int d2=A[i]-A[i-1];
            if(d2==d1)
                sum+=(++dp);
            else
                dp=0;
            d1=d2;
        }
        return sum;
    }
};
```