class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 0;
        stack<int> s;
        ListNode *temp=head;
        while(temp){
            count++;
            if(count >= left && count <= right){
                s.push(temp->val);
            }
            temp=temp->next;
        }
        count=0;
        temp=head;
        while(temp){
            count++;
            if(count>= left && count<=right){
                temp->val= s.top();
                s.pop();
            }
            temp=temp->next;
        }
        
        return head;
    }
};