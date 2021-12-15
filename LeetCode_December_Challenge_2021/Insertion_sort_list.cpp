
// Time Complexity O(n^2)
// Space Complexity O(1)

class Solution {
public:
    void insertNode(ListNode* head,ListNode* node){
        while(head->next && head->next->val < node->val) head=head->next;
        node->next=head->next;
        head->next=node;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead=new ListNode(0);
        
        while(head){
            ListNode* node=head;
            head=head->next;
            insertNode(newHead,node);
        }
        return newHead->next;
    }
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* newHead=new ListNode(0);
        ListNode* cur=head;
        ListNode* prev=newHead;
        ListNode* next=nullptr;
        while(cur){
            next=cur->next;
            while(prev->next && prev->next->val < cur->val) prev=prev->next;
            cur->next=prev->next;
            prev->next=cur;
            prev=newHead;
            cur=next;
            
        }
        return prev->next;
    }
};