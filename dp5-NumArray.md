**问题**：

给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

**思路**

- 我以为要创建一个dp[i][j]二维数组，i代表起始，j代表结束，则状态转移方程dp[i][j] = dp[i-1][j] + nums[i] || dp[i][j-1] + nums[j]，边界条件为 dp[0][0] = nums[0].
- 但是题目中的NumArray 为一个数组，下标为n是nums[0]到nums[n]元素相加的总和
- 所以只要拿0到j - 0到i的差就是j到i的和

```c++
class NumArray {
    public:
        vector<int> ans;
        NumArray(vector<int> nums){
            ans.resize(nums.size()+1,0);
            ans[0] = 0;
            for(int i=0 ;i<nums.size();i++) {
                ans[i+1] = ans[i] + nums[i];
            }
        }
        int sumRange(int i,int j ){
            return ans[j+1] - ans[i];
        }
}

```