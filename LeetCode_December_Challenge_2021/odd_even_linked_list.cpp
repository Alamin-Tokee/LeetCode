//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *odd=head, *even=head->next, *evenHead=even;
        
        while(even!=NULL and even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return NULL;
        int oddEvenIndicator = 1;
        ListNode* lastOddNode = head;
        ListNode* firstEvenNode = head->next;
        ListNode* lastEvenNode=head->next;
        ListNode* currNode = head->next->next;
        
        while(currNode!=NULL){
            if(oddEvenIndicator % 2 == 0){
                lastEvenNode->next = currNode;
                lastEvenNode=currNode;
            }else{
                lastOddNode->next = currNode;
                lastOddNode = currNode;
            }
            currNode=currNode->next;
            oddEvenIndicator++;
        }
        lastOddNode->next = firstEvenNode;
        lastEvenNode->next=NULL;
        return head;
    }
};