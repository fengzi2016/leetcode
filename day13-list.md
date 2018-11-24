
```c++
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
   };
    SinglyListNode* l;
    /** Initialize your data structure here. */
   
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        SinglyListNode* tmp = l;
        while(index--) {
            tmp = tmp->next;
            if(tmp->next==NULL) return -1;
        }
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* n = new SinglyListNode(val);
        n -> next = l;
        l = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode* tmp = l;
        while(tmp->next!=NULL) {
            tmp = tmp->next;
        }
        SinglyListNode* n = new SinglyListNode(val);
        tmp->next = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       
        SinglyListNode* n = new SinglyListNode(val);
        if(index==0){
            n->next = l;
            l = n;
            return;
        }
        SinglyListNode* pre = l;
        index --;
        while(index>0){
            pre = pre -> next;
            index--;
        }
        
        if(pre->next!=NULL){
            SinglyListNode* next = pre->next;
            n -> next = next;
            pre->next = n;
        }else{
            pre->next = n;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        SinglyListNode* tmp = l;
        if(index<0) return;
        if(index==0) l=tmp->next;
        index --;
        while(index>0) {
            if(tmp->next==NULL) return;
            tmp = tmp -> next;
            index --;
        }
        SinglyListNode* next = tmp->next;
        tmp->next = next->next;
    }
```