//Normal Multiplication
//Time complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=head->val;
        while(head->next!=NULL){
            num=(num<<1) | head->next->val;
            head=head->next;
        }
        return num;
    }
};
//Normal Bit wise shift
//Time complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=head->val;
        while(head->next!=NULL){
            num=(num*2) + head->next->val;
            head=head->next;
        }
        return num;
    }
};