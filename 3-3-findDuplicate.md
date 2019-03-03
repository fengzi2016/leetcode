# 寻找重复数
## [题目链接](https://leetcode-cn.com/explore/interview/card/top-interview-quesitons-in-2018/270/sort-search/1172/)
## 思路
- 遍历，当前的和后面的下标值相比
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int tmp;
        for(int i = 0; i < nums.size() - 1; i++){
            tmp = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] == tmp) {
                    return tmp;
                }  
            }
        }
        return 0;
    }
};
```