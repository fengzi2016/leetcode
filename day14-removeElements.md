**移除链表元素**

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6

输出: 1->2->3->4->5

- 思路：遍历，是的话就跳过，边界处理。
```c++

    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur,*next,*pre;
        if(head==NULL) return head;
        while(head->val == val ) {
            if(head->next)head = head->next;
            else {
                head=NULL;
                break;
            }
        }
        if(head==NULL || head->next == NULL) return head;
        pre = head;
        if(pre->next) cur = pre -> next;
        if(cur) next = cur -> next;
        while(cur && cur -> next){
            if(cur -> val == val) {
                pre -> next = next;
            }else{
                 pre = cur;
            }
            cur = pre -> next;
            next = cur -> next;
        }
        if(cur -> val == val )  pre->next = NULL;
        return head;
    }
```