class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* tmp=new ListNode(-1);
        tmp->next=head;
        ListNode* prev=tmp;
        while(head!=NULL && head->next!=NULL){
            
            if(head->val==head->next->val){
                while(head->next!=NULL && head->val==head->next->val){
                     head=head->next;
                }
                head=head->next;
                prev->next=head;
            }
            else{
                prev=head;
                head=head->next;
            }
        }
        
        return tmp->next;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0, head);
        ListNode* i = res;
        
        while(i->next){
            ListNode* j = i->next;
            
            if(j->next and j->val == j->next->val){
                while(j->next and j->val == j->next->val){
                    j = j->next;
                }
                i->next = j->next;
            }
            else{
                i = j;
            }
        }
        
        return res->next;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;

        if (head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
        }
        else {
            while (head->next && head->next->val == head->val)
                head = head->next;
            return deleteDuplicates(head->next);
        }
        
        return head;
    }
};