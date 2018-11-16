# DFS模版
```c++
 bool DFS(Node cur,Node target,Set<Node>visited){
     return true if cur == target;
     for(next:each neighbor of cur) {
         if(next is not visited) {
             add next to visited;
             return true if DFS(next,target,visited) == true;
         }
     }
     return false;
 }
```