
**回文链表**

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2

输出: false

示例 2:

输入: 1->2->2->1

输出: true

- 思路：借用一个栈，再遍历栈和链表
```c++
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* tmp = head;
        while(tmp){
            s.push(tmp);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            ListNode* cur = s.top();
            s.pop();
            if(cur->val != tmp->val) return false;
            tmp = tmp -> next;
        }
        return true;
    }
```