#include<iostream>
// #include<cstdio>
#include<algorithm>
// #include<stdio.h>
#include<vector>
#include<stack>
// #include<unordered_map>
// #include<unordered_set>
// #include<numeric> 
// #include<map>
// #include<queue>

// using namespace std;

// int fn(int n){
//     if(fibs[n]!=-1) {
//       return fibs[n];
//     }else{
//         fibs[n]=fn(n-1)+fn(n-2);
//         return fibs[n];
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     fibs[0] = 0;
//     fibs[1] = 1;
//     cout<<fn(n);
// }

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <math.h>
#include <map>

using namespace std;
vector<int> arr;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void Qsort(vector<int>& A, int low, int high) {
    if(high <= low) return;
    int i = low;
    int j = high;
    int key = A[low];
    while(true){
        /*从左向右找比key大的值*/
        while(A[i++]<key){
            if(i == high) break;
        }

        /*从右向左找比key小的值*/
        while(A[j--]>key){
            if(j == low) break;
        }
        if(i >= j ) break;
        /*交换i,j对应的值*/
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;

    }
    /*中枢值与j对应值交换*/
    int tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;
    Qsort(A, low, j-1);
    Qsort(A, j+1, high);

}
vector<int> sortedSquares(vector<int>& A) {
    for(int i = 0; i < A.size(); i++){
        if(A[i] < 0) A[i] = -A[i];
    }
    Qsort(A,0, A.size());
    return A;
}

/******************************结束写代码******************************/


int main() {
	vector<int> arr;
    int a[] = {-4,-1,0,3,10};
    for(int i = 0; i < 5; i++){
       arr.push_back(a[i]);
    }
    sortedSquares(arr);
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}