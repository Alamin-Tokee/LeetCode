//TC O(n)
//SC O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next) return;
        
        ListNode *slow=head, *fast=head;
        
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *mid=slow->next;
        slow->next = NULL;
        ListNode* p=mid, *q=mid->next, *pp=NULL, *qq=NULL;
        mid->next = NULL;
        
        while(q){
            pp=p;
            p=q;
            q=q->next;
            p->next=pp;
        }
        mid=p;
        
        p=head;
        q=mid;
        
        while(q){
            pp = p; qq = q;
            p=p->next;q=q->next;
            pp->next=qq;qq->next=p;
        }
    }
};

//TC O(n^2)
//SC O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        
        ListNode *fast = head;
        
        while(fast->next->next) fast = fast->next;
        fast->next->next = head->next;
        head->next=fast->next;
        fast->next = NULL;
        
        reorderList(head->next->next);
    }
};