## 广度优先模板
- 如果可以确保不会重复添加子结点，比如树，或者需要重复添加子节点
```java
    int BFS(Node root , Node target){
        Queue<Node> queue;
        int step = 0;
        add root to queue;
        while(queue is not empty){
            step = step + 1;
            //iterate the nodes which are already in the queue
            int size = queue.size();
            while(int i=0;i<size;++i){
                Node cur = the first node in queue;
                return step if cur is target;
                for(Node next : the neighbors of cur){
                    add next to queue;
                }
                remove the first node from queue;
            }
            
        }
        return -1;
    }
```
- 如果要杜绝重复添加子节点，又不能确保。则加一个set
```java
    int BFS(Node root,Node target){
        Queue<Node> queue;
        Set<Node> set;
        add root to queue;
        add root to set;
        int step = 0;
        while(queue is not empty){
            step += 1;
           int size = queue.size();
           for(int i=0;i<size;i++){
               Node cur  = the first node in the queue
               return step if cur is the target;
               for(Node next : the neighbors of cur){
                   if (next is not in used) {
                    add next to queue;
                    add next to set;
                    }
               }
               remove the first node from queue;

           }

        }
        return -1;
    }
```