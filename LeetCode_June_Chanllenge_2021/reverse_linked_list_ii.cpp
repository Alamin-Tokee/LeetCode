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


//Using Recursion 

class Solution {
public:
    ListNode* Reverse(ListNode* head,ListNode* right){
        if(!head || !head->next || head==right) return head;
        
        ListNode* last=Reverse(head->next,right);
        head->next->next=head;
        head->next=NULL;
        
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode=NULL;
        ListNode* leftPrev=NULL;
        ListNode* RightNode=NULL;
        ListNode* rightNext=NULL;
        
        ListNode* curr = head;
        int c=1;
        while(c < left){
            leftPrev = curr;
            curr=curr->next;
            c++;
        }
        leftNode=curr;
        
        while(c < right){
            curr=curr->next;
            c++;
        }
        
        RightNode=curr;
        
        rightNext=RightNode->next;
        
        ListNode* temp=Reverse(leftNode,RightNode);
        
        if(leftPrev && leftPrev->next){
            leftPrev->next->next=rightNext;
            leftPrev->next=temp;
        }else{
            head->next=rightNext;
            head=temp;
        }
        
        return head;
    }
};


//Iterative Approach 

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL ||  head->next==NULL) return head;
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* node=dummy;
        ListNode* preNode=NULL;
        
        for(int i=0;i<left;i++){
            preNode=node;
            node=node->next;
        }
        ListNode* NodeR=node;
        ListNode* preN=preNode;
        
        for(int i=left;i<=right;i++){
            ListNode* forward=NodeR->next;
            NodeR->next=preN;
            preN=NodeR;
            NodeR=forward;
        }
        preNode->next=preN;
        node->next=NodeR;
        
        return dummy->next;
        
    }
};