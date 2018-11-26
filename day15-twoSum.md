**题目**

- 两数之和

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]

**思路**
利用一个哈希表【int,vector< int >】，键为每个元素的值，值的类型为向量，值的内容是每个元素对应的下标

```c++
    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , vector<int>> hashMap;
        for(int i=0;i<nums.size();i++) {
            hashMap[nums[i]].push_back(i); 
        }
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target){
                    if(nums[i]==nums[j]) {
                        res.push_back(hashMap[nums[i]][0]);
                        res.push_back(hashMap[nums[i]][1]);
                    }else {
                         res.push_back(hashMap[nums[i]][0]);
                         res.push_back(hashMap[nums[j]][0]);
                    }
                   
                    return res;
                }
            }
        }
        return res;
    }
};
```