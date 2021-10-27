class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node=head;
        while(node!=NULL and node->next!=NULL){
            if(node->val==node->next->val){
                node->next=node->next->next;
                
            }else{
                node=node->next;
            }
        }
        return head;
    }
};


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head || !(head -> next)){
			return head;
		}
		if(head -> val == head -> next -> val){
			ListNode* temp = head -> next;
			head -> next = head -> next -> next;
			delete temp;
			deleteDuplicates(head);
		}
		else{
			deleteDuplicates(head -> next);
		}
		return head;
	}
};
