//Iterative Approach
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* node=head;
        while(node){
            if(node->child){
                Node* cur=node->child;
                while(cur->next) cur=cur->next;
                cur->next=node->next;
                if(node->next) node->next->prev=cur;
                node->next=node->child;
                node->child->prev=node;
                node->child=nullptr;
            }
            node=node->next;
        }
        
        return head;
    }
};

//Recursive Approach
class Solution {
public:
    Node* flattenUtil(Node *head) {
        Node* current = head;
        Node* prev = NULL;
        while(current) {
            if(current -> child) {
                Node* tcurrent = current -> next;
                current -> next = current -> child;
                (current -> next) -> prev = current;
                current -> child = NULL;
                current = flattenUtil(current -> next);
                if(tcurrent) {
                    tcurrent -> prev = current;
                    current -> next = tcurrent;
                }
            }
            prev = current;
            current = current -> next;
        }
        return prev;
    }
    Node* flatten(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        Node* current = head;
        flattenUtil(current);
        return head;
    }
};