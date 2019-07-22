# 划分为k个相等的子集
## 题目
```
输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4

输出： True

说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```
## 思路

- 递归求解
- 从0到n遍历，用visited向量记录nums[i]是否已经被使用
- 用cur_sum记录已经累加的和值，当sum == target时，重置sum
- 用cur_num记录已经累加的数量，当sum == target时，重置cur_num
## 代码
```c++
   bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num:nums)sum+=num;
        if(k <= 0 || sum%k != 0)return false;
        vector<int> visited(nums.size(), 0);
        return canPartition(nums, visited, 0, k, 0, 0, sum/k);
    }
    
    bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int cur_num, int target){
        if(k==1)return true;
        if(cur_sum == target && cur_num >0 )return canPartition(nums, visited, 0, k-1, 0, 0, target);
        for(int i = start_index; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))return true;
                visited[i] = 0;
            }
        }
        return false;
    }
```