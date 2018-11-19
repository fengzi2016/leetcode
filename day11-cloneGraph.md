**题目**
- [克隆图](https://leetcode-cn.com/explore/learn/card/queue-stack/219/stack-and-dfs/884/)

**思路**

- 广度优先
```c++
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return node;
        queue<UndirectedGraphNode* > q;
        map<UndirectedGraphNode*,bool> visited;
        map<UndirectedGraphNode*,UndirectedGraphNode*> newnode;
        UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
        visited[node]=true;
        newnode[node]=newNode;
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            for(int i=0;i<cur->neighbors.size();i++){
                if(!visited[cur->neighbors[i]]){
                    // 创立新节点
                    UndirectedGraphNode * tmp = new UndirectedGraphNode(cur->neighbors[i]->label);
                    // 设置已经访问过
                    visited[cur->neighbors[i]] = true;
                    // 将这个节点添加到新图中
                    newnode[cur->neighbors[i]] = tmp;
                    // 将这个节点添加到新图中原参照节点的neighbors中
                    newnode[cur]->neighbors.push_back(tmp);
                    q.push(cur->neighbors[i]);
                }else{
                    // 将已经访问过的节点在新图中的信息添加到当前节点的neighbors中
                    newnode[cur]->neighbors.push_back(newnode[cur->neighbors[i]]);
                }
            }
        }
        return newNode;
    }
```