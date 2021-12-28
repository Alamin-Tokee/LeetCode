//Time Complexity (N+N/2)
//Space Complexity O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* node=head;
        int count=0;
        while(node->next!=NULL){
            count++;
            node=node->next;
        }
        ListNode* no=head;
        int c= count%2 ? (count/2) : (count/2)-1;
        int i=0;
        while(i<=c){
            no=no->next;
            i++;
        }
        
        head=no;
        
        return head;
    }
};

//Time Complexity O(N)
//Space complexity O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};


//Time Complexity O(N)
//Space Complexity O(N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*>v(100);
        int i=0;
        while(head!=NULL){
            v[i++]=head;
            head=head->next;
        }
        return v[i/2];
    }
};

//Time Complexity (N+N/2)
//Space Complexity O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* node=head;
        int count = 1;
        while(node->next!=NULL){
            count++;
            node=node->next;
        }
        ListNode* current=head;
        int middle = count/2;
        int i = 0;
        while(i < middle){
            current = current->next;
            i++;
        }
        
        return current;
    }
};