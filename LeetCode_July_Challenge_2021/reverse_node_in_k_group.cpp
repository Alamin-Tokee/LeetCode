//Recursive Approach

class Solution {
public:
    ListNode* reverse(ListNode* first,ListNode* last){
        ListNode* prev=last;
        while(first!=last){
            auto tmp=first->next;
            first->next=prev;
            prev=first;
            first=tmp;
        }
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node=head;
        for(int i=0; i<k; ++i){
            if(!node) return head;
            node=node->next;
        }
        auto new_head=reverse(head,node);
        head->next=reverseKGroup(node,k);
        
        return new_head;
    }
};

//Using Vector
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>a;
        ListNode *temp=head;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *c=NULL;
        ListNode *b=NULL;
        int p=a.size() / k;
        for(int i=0;i<p;i++){
            reverse(a.begin()+k*i,a.begin()+k*i+k);
        }
        for(int i=0;i<a.size();i++){
            if(b==NULL){
                b=new ListNode(a[i]);
                c=b;
            }else{
                b->next=new ListNode(a[i]);
                b=b->next;
            }
        }
        
        return c;
    }
};


//Iterative approach
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *curr=head,*prev,*next_node,*start_prev,*start_curr;
        while(curr!=NULL){
            n++,curr=curr->next;
        }
        n=n/k;curr=head;
        for(int i=0;i<n;i++){
            prev=NULL;
            start_curr = curr;
            for(int j=0;j<k;j++){
                next_node = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next_node;
            }
            if(i==0) head=prev;
            if(i > 0) start_prev->next= prev;
            
            start_prev=start_curr;
        }
        if(start_curr) start_curr->next = curr;
        
        return head;
    }
};
