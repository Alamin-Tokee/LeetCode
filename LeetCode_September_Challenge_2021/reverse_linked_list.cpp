//Iterative Approach
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node=head;
        ListNode* pre=NULL;
        ListNode* n;
        while(node!=NULL){
            n=node->next;
            node->next=pre;
            pre=node;
            node=n;
        }
        return pre;
    }
};

//Recursive Approach
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
};