//TC O(n)
//SC O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* pre = temp;
        
        while(head!=NULL){
            if(head->next!=NULL and head->val == head->next->val){
                while(head->next!=NULL && head->val == head->next->val){
                    head = head->next;
                }
                pre->next = head->next;
            }else{
                pre = pre->next;
            }
            head = head->next;
        }
        return temp->next;
    }
};


//TC O(n) 
//SC O(n) For recursive call
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *node = head->next;
        if(head->val != node->val){
            head->next = deleteDuplicates(node);
            return head;
        }else{
            while(node && node->val == head->val) node = node->next;
            return deleteDuplicates(node);
        }
    }
};
