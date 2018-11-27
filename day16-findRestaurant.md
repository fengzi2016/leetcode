**题目**

- 两个列表的最小索引总和

假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:

["Shogun", "Tapioca Express", "Burger King", "KFC"]

["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]

输出: ["Shogun"]

解释: 他们唯一共同喜爱的餐厅是“Shogun”。

**思路**

利用2个unordered_map< string , int >, 键存string，值存string的下标。再对其中一个hashMap进行遍历，遍历函数内对最小值进行比较和存储。

```c++
    class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> hashMap1;
        unordered_map<string,int> hashMap2;
        for(int i=0;i<list1.size();i++){
            hashMap1[list1[i]] = i;
        }
        for(int j=0;j<list2.size();j++){
            hashMap2[list2[j]] = j;
        }
        vector<string> res;
        int minum = 10001;
        for(auto it = hashMap1.begin();it != hashMap1.end();it++){
            if(hashMap2.count(it->first)) {
                int sum = it->second + hashMap2[it->first];
                if(sum==minum){
                    res.push_back(it->first);
                }else if(sum<minum){
                    res.clear();
                    res.push_back(it->first);
                    minum = sum;
                }
            }
        }
        return res;
    }
};
```
