
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node=head;
        ListNode* prev=NULL;
        while(node!=NULL){
            if(node->val==val){
                if(prev==NULL){
                    head=head->next;
                    node=head;
                }else{
                    prev->next=node->next;
                    node=node->next;
                }
            }else{
                prev=node;
                node=node->next;
            }
        }
        return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        while(dummy!=NULL and dummy->next!=NULL){
            if(dummy->next->val==val){
                ListNode* temp=dummy->next;
                dummy->next=dummy->next->next;
                delete(temp);
            }else{
                dummy=dummy->next;
            }
        }
        return pre->next;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        if(head->val==val){
            head=removeElements(head->next,val);
            return head;
        }else{
            head->next=removeElements(head->next,val);
            return head;
        }
    }
};


