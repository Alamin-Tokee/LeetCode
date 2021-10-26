
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