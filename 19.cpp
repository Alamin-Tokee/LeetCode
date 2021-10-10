
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;
        int count=1;
        while(node->next!=NULL){
            node=node->next;
            count++;
        }
        if(n > count) return NULL;
        if(n==count){
            head=head->next;
            return head;
        }
        int steps=count-n-1;
        node=head;
        while(steps--){
            node=node->next;
        }
        node->next=node->next->next;
        
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        if(head==NULL) return head;
        
        head->next = removeNthFromEnd(head->next,n);
        n--;
        if(n==0)
            return head->next;
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        ListNode *t=new ListNode(0,head), *p=t, *q=t;
        for(;n--;q=q->next);
        
        for(;q->next!=NULL p=p->next,q=q->next);
        
        q=p->next;
        p->next=q->next;
        delete(q);
        
        return t->next;
    }
};