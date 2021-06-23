//Using Stack 

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


//Using Vector 


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head==NULL)
            return NULL;
        
        vector<int> v;
        
        ListNode *temp = head;
        
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        for(int i=0;i<left-1;i++)
            temp = temp->next;
        
        for(int i=right;i>=left;i--)
        {
            temp->val = v[i-1];    
            temp = temp->next;
        }
        
        return head;
    }
};
