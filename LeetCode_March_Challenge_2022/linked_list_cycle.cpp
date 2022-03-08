//TC O(n)
//SC O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
    
        unordered_map <ListNode *,int> visited;
        ListNode *t=head;
        if(t==NULL)
            return false;
        if(t->next ==NULL)
            return false;
        while(t->next)
        {
            if(visited[t->next]==1)
                return true;
            t=t->next;
            visited[t]=1;
        }
        return false;
        
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow=head, *fast=head->next;
        
        while(slow!=NULL and fast!=NULL and fast->next!=NULL){
            if(slow==fast) return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};

//TC O(n)
//SC O(n1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        
        while(p!=NULL and q!=NULL and q->next!=NULL and q->next->next!=NULL){
            p=p->next;
            q=q->next->next;
            if(p==q) return true;
        }
        return false;
    }
};

//TC O(n)
//SC O(n)
class Solution {
private:
    bool recursiv(ListNode* slow,ListNode* fast)
    {
        if(fast == NULL || fast->next == NULL)return false;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return true;
        return recursiv(slow,fast);
    }
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return false;
        return recursiv(head,head);
        
    }
};