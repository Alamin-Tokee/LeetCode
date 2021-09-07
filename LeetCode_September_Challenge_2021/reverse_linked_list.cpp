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