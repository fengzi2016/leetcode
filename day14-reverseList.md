- 题目：

**反转一个单链表**

示例:

输入: 1->2->3->4->5->NULL

输出: 5->4->3->2->1->NULL

- 迭代：
```c++
     ListNode * reverseList(ListNode* head){
        if(head==NULL || head->next == NULL) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *next = NULL;
        while(cur){
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        head->next = NULL;
        head = pre;
        return head;   
    }
```
- 递归：
```c++
      ListNode *reverseList(ListNode* head) {
        //异常判断(NULL==head)结束条件(NULL==head->nex),
        // 即head为最后一个节点时，将该节点返回，即为转置链表的头节点。
       if ( (NULL == head) || (NULL == head->next) )
	            return head;
        //  递归后续链表（即以head->next为首节点的链表）
        ListNode* trail = reverseList(head->next);
        //上一步执行完后，head->next为后续链表的末尾节点，
        //所以让head->next的next指向当前节点head
        head -> next -> next = head;
        // 当前节点的next指向NULL
        head -> next = NULL;
        // 返回后续链表的头指针
        return trail;
    }
```