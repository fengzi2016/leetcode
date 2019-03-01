# 排序算法
## 冒泡排序
### c++
```c++
  vector<int> maopao(vector<int> nums) {
    for(int i = 0; i < nums.size() - 1; i++){
      for(int j = 0; j < nums.size() - 1 - i; j++){
        if(nums[j]>nums[j+1]){
          swap(nums[j],nums[j+1]);
        }
      }
    }
  }
```
### js
```js
  function maopao(nums){
    for(let i = 1; i < nums.length - 1; i++){
      for(let j = 0; j < nums.length - 1 - i; j++ ){
        if(nums[j]>nums[j+1]){
          let tmp = nums[j];
    		  nums[j] = nums[j+1];
    		  nums[j+1] = tmp;
        }
      }
    }
    return nums;
  }
  
```
速记码
>  i∈[1,N-1)               //循环N-1遍
>  j∈[0,N-1-i)           //每遍循环要处理的无序部分
>  swap(j,j+1)          //两两排序（升序/降序）

## 插入排序
### c++
```c++
  void insertion_sort(vector<int> nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
      int cur = nums[i];
      int j = i - 1;
      while((j >= 0) && (nums[j] > cur)){
        nums[j+1] = nums[j];
        j--;
      }
      nums[j+1] = cur;
    }
  }
```
### js
```js
  function insertion_sort(nums){
    for(let i = 1; i < nums.length; i++){
      let cur = nums[i];
      j = i - 1;
      while((j>=0) && (nums[j] > cur)){
        nums[j+1] = nums[j];
        j--;
      }
      nums[j+1] = cur;
    }
    return nums;
  }
```
## 计数排序
- 3个数组，原始数组，tmp数组，排序后数组
- tmp数组第一次用下标映射原始数组元素值，记录每个元素的出现数量
- 将tmp数组内的元素累加，映射当前下标代表的最终排序的序号
### C++ 

```c++
  void count_sort(vector<int> nums){
    vector<int> tmp(100,0);
    vector<int> ans(nums.size());
    for(int i = 0; i < nums.size(); i++){
      tmp[nums[i]]++;
    }
    for(int j = 1; j < tmp.size() ; j++){
      tmp[j] = tmp[j-1] + tmp[j];
    }
    for(int x = 0; x < nums.size(); x++){
      int cur = nums[x];
      ans[tmp[cur] - 1] = cur;
      tmp[cur] -= 1;
    }
  }
```

### js
```js
function jishu(nums){
  let tmp = Array(100).fill(0), ans = [];
  for(let i = 0; i < nums.length; i++){
    tmp[nums[i]]++;
  }
  for(let i = 1; i < nums.length; i++){
    tmp[i] = tmp[i - 1] + tmp[i];
  }
  for(let i = 0; i < nums.length; i++){
    let cur = nums[i];
    ans[tmp[cur] - 1] = nums[i];
    tmp[cur] --;
  }
  return ans;
}
```

## 快速排序
### js 递归法
```js
  Array.prototype.quickSort = function() {
    const l = this.length;
    if(l < 2) return this;
    const basic = this[0], left = [] , right = [];
    for(let i = 1; i < l; i++){
      const iv = this[i];
      iv >= basic && right.push(iv);
      iv < basic && left.push(iv);
    }
    return left.quickSort().concat(basic,right.qucikSort());
  }
```
### c 非递归法

```c++
int Partition(int arr[], int left, int right)
{
	int key = arr[left];		// 将一个数作为基准值
	int i = left, j = right;
 
	while(i < j)
	{
		// 从最右边找第一个小于基准值的数字
		while(i < j && arr[j] >= key) j--;
		arr[i] = arr[j];	// 放在基准值左边
 
		// 从最左边找第一个大于基准值的数字
		while(i < j && arr[i] <= key) i++;
		arr[j] = arr[i];	// 放在基准值的右边
	}
 
	arr[i] = key;		    // 确定基准值的位置
	return i;				// 返回基准值的位置
}
 
void QuickSort1(int arr[], int n)
{
	if (n <= 1) return;
	stack<int> SStack;
 
	// 将最大的区间压入栈
	SStack.push(0);
	SStack.push(n-1);
 
	int left, right, mid;
	while(!SStack.empty())
	{   // 注意按相反的顺序取出两边大小
 
		right = SStack.top();
		SStack.pop();
		left = SStack.top();
		SStack.pop();
 
		// 计算基准值的位置进行新子区间划分
		mid = Partition(arr, left, right);
	
		// 将左边新区间入栈
		if (mid-1 > left)
		{
			SStack.push(left);
			SStack.push(mid-1);
		}
 
		//将右边新区间入栈
		if (mid+1 < right)
		{
			SStack.push(mid+1);
			SStack.push(right);
		}
	}
}
```

## 归并排序
### js
```js
// 无限分割数组，并且递归
 function mergeSort(arr){
   if(arr.length<2)return arr;
   const mi = Math.floor(arr.length / 2);
   const left = arr.slice(0,mi);
   const right = arr.slice(mi);
   return merge(mergeSort(left),mergeSort(right));
 }
 // 将传入的两个数组进行依次排序
 function merge(left,right){
   const result = [];
   while(left.length > 0 && right.length > 0){
     if(left[0]<right[0]){
       result.push(left.shift());
     }else{
       result.push(right.shift());
     }
   }
   return result.concat(left,right);
 }
```