//Time Complexity O(N)
//Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head;
        if(l1->val<=l2->val){
            head=l1;
            head->next=mergeTwoLists(l1->next,l2);
        }else{
            head=l2;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};

//Time Complexity O(N)
//Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head;
        if(l1->val<=l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

//Time Complexity O(N)
//Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        
        ListNode* head = new ListNode();
        ListNode* node = head;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                node->next=l1;
                node=node->next;
                l1=l1->next;
            }else{
                node->next=l2;
                node=node->next;
                l2=l2->next;
            }
        }
        while(l1!=NULL){
            node->next=l1;
            node=node->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            node->next=l2;
            node=node->next;
            l2=l2->next;
        }
        return head->next;
    }
};

//Time Complexity O(N)
//Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* dummy=new ListNode();
        ListNode* p=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                p->next=l1;
                l1=l1->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        p->next=(l1!=NULL) ? l1 : l2;
        return dummy->next;
    }
};