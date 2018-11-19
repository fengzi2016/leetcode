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

```c++
    /*
 * Return true if there is a path from cur to target.
 */
boolean DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> s;
    add root to s;
    while (s is not empty) {
        Node cur = the top element in s;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to s;
                add next to visited;
            }
        }
        remove cur from s;
    }
    return false;
}

```