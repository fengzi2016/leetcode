**题目**

- 相交链表
编写一个程序，找到两个单链表相交的起始节点。

 

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。

 

注意：

如果两个链表没有交点，返回 null.

在返回结果后，两个链表仍须保持原有的结构。

可假定整个链表结构中没有循环。

程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。


- 自己思路：两个栈，将链表放入，再依次同时弹出，找到相同的时候，并返回，如果最后都弹完了则没有。

```c++
```

- 成功思路：先遍历出两个链表的长度n，m,如果最后一个节点不同则一定没有相交节点；长的链表从n-m开始，则同时往后走一定会遇到相同的一个节点，如果没有则是没有链接。

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) {
            return NULL;
        }
        ListNode* A;
        ListNode* B;
        A=headA;
        B=headB;
        int lenA = 1,lenB = 1;
        while(A->next){
            A=A->next;
            lenA++;
        }
        while(B->next){
            B=B->next;
            lenB++;
        }
        if(A!=B)return NULL;
        A=headA;
        B=headB;
        if(lenA>lenB){
            int ca = lenA-lenB;
            while(ca--){
                A = A->next;
            }
        }else{
            int ca = lenB-lenA;
            while(ca--){
                B = B->next;
            }
        }
        while(A!=B){
           A=A->next;
           B=B->next;
        }
        return A;
        
    }
};
```