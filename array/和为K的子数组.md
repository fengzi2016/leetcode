
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
//动态规划
// 假设有一段子数组[i,j] 的值为k
// 则用一个数组记录从[0,n]的总和
// 假设j>i
// 则[i,j]的总和为[0,j] - [0,i-1]的总和
// 用一个map来记录总和为sum的子数组的个数
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int sum = 0, res = 0;
        int n = nums.size();
        cnt[0] = 1;
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            if(cnt.count(sum-k)){
                res += cnt[sum-k];
            }
            cnt[sum]++;
        }
        return res;
    }
};
```

```c++
// 自己 超时
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int start = 0 , j = 0;
        subarraySum(nums, start, k, count, k, j);
        return count;
    }
private:
    void subarraySum(vector<int>& nums, int start, int k, int& count, int target, int j) {
        if(start>=nums.size()){return;}
        if( j>=nums.size()) {
            start++;
            j=start;
            subarraySum(nums, start, target, count, target, j); 
            return;
        }
        k -= nums[j++];
        if(k==0) {
            count++;
            start++;
            j=start;
            subarraySum(nums, start, target, count, target, j); 
            return;
        }
        subarraySum(nums, start, k, count, target, j);
        return;
    }
};
```