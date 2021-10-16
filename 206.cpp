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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
};


class Solution {
public:
    ListNode* solve(ListNode* current, ListNode* back)
    {
        if(!current) 
            return back;
        ListNode* newnode = solve(current->next, current);
        current->next = back;
        return newnode;
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        return solve(head, nullptr);
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        function<ListNode*(ListNode*, ListNode*)> f = [&] (auto l, auto p) {
            if (!l) return p;
            auto ans = f(l->next, l);
            l->next = p;
            return ans;
        };
        return f(head, nullptr);
    }
};