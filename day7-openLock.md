**题目**
- 打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

**思路**
- 广度优先，类似于迷宫+障碍物，每次挑选8个方向，2的4次方

```c++
   int openLock(vector<string>& deadends, string target) {
       unordered_set<string> deadlock(deadends.begin(),deadends.end());
       queue<string> q({"0000"});
       unordered_set<string> visited({"0000"});
       if (deadlock.count("0000")) return -1;
       int step = 0;
       while(!q.empty()){
           step++;
           int size = q.size();
           for(int i=0;i<size;i++){
             string cur = q.front();
               q.pop();
              
               for(int j=0;j<cur.size();j++){
                   char t = cur[j];
                   string str1 = cur.substr(0,j)+ to_string(t=='9'?0:t-'0'+1)+cur.substr(j+1);
                   string str2 = cur.substr(0,j)+ to_string(t=='0'?9:t-'0'-1)+cur.substr(j+1);
                   if(str1==target || str2 == target) return step;
                   if(!deadlock.count(str1)&&!visited.count(str1)) q.push(str1);
                   if(!deadlock.count(str2)&&!visited.count(str2)) q.push(str2);
                    visited.insert(str1);
                    visited.insert(str2);
               }
           }
           
       }
       return -1;


   } 
```