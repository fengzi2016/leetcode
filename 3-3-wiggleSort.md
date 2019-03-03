# 摆动序列II
## [题目链接](https://leetcode-cn.com/explore/interview/card/top-interview-quesitons-in-2018/270/sort-search/1170/)
## 思路
- 排序之后，将数组前半部分放在偶数位置，后半部分放在奇数位置
```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> tmp = nums;
       int m = (nums.size() + 1)/2;
       int last = nums.size();
       sort(tmp.begin(), tmp.end());
       for(int i = 0; i < nums.size(); i++){
           nums[i] = i%2 == 0 ? tmp[--m] : tmp[--last];
       }
    }
};
```