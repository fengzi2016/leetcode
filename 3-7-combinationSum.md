# 组合总和IV
## [题目链接](https://leetcode-cn.com/problems/combination-sum-iv/)
## 思路
- 目标值target，记录数组comb， comb[target]表示有comb[target]种方法相加达到target
- 递归
- dp

## 代码

**递归**
```js
function combinationSum4(arr, target){
  if(target === 0){
    return 1;
  }
  let res = 0;
  for(let i = 0; i < nums.length; i++){
    if(target >= nums[i]){
      res += combinationSum4(nums, target - nums[i]);
    }
  }
  return res;
}
```

**动态规划**
- 自顶向下
```c++
  class Solution{
    public: 
      vector<int> dp;
      int combinationSum4(vector<int>&nums, int target){
        dp.resize(target+1);
        dp.assign(target+1,-1);
        dp[0] = 1;
        return helper(nums,target);
      }
      int helper(vector<int> & nums, int target){
        if(dp[target]!=-1){
          return dp[target];
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
          if(target >= nums[i]){
            res += helper(nums,target-nums[i]);
          }
        }
        dp[target] = res;
        return res;
      }
  }
```

- 自底向上

```javascript
var combinationSum4 = function(nums, target) {
    var res = new Array(target+1);
    res.fill(0);
    res[0] = 1;
    console.log(res);
    for(let i = 1; i < res.length; i++){
      for(let j = 0; j < nums.length; j++){
        if(i >= nums[j]){
          res[i] += res[i - nums[j]];
        }
      }
    }
    return res[target];
};
```