**题目：**
复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝


**思路：**
1. 建立哈希表，然后遍历链表，深复制的同时将复制的旧节点作为key，新节点作为value存进哈希表，第二次遍历 以原链表的一个节点的随机指针值作为索引，查找对应的新链表的对应节点的随机指针值

2. 将链表重新添加成这样
![xxx](https://img-blog.csdn.net/20160511183943780?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

 - 之后添加之后依此添加random指针： newNode -> random = oldNode -> random -> next; 为什么为next呢，因为要指向新的random节点而不是旧的，而新的random节点由原random节点的next指针指向。
 - 再遍历新链表一遍删除原来的旧节点



```c++
   RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        // write your code here
        map<RandomListNode*,RandomListNode*> hash;
        
        RandomListNode *curr = head;
        RandomListNode *newHead = new RandomListNode(curr->label);
        
        RandomListNode * newCurr = newHead;
        
        hash[curr] = newHead;
        
        while(curr->next) {
            curr = curr -> next;
            RandomListNode *newNode = new RandomListNode(curr->label);
            hash[curr] =  newNode;
            newCurr->next = newNode;
            newCurr = newCurr->next;
            
        } 
        
         newCurr = newHead;
         curr = head;
        while(newCurr) {
            
            newCurr->random = hash[curr->random];
            newCurr = newCurr->next ;
            curr = curr->next;
    }
    return newHead;
    }
```