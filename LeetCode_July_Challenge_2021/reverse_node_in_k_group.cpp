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