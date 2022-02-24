//Time Complexity O(nlogn)
//Space Complexity O(logn) // For call recursive function 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        
		// divide linked list to apply sorting during merging
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
		// merge divided linked list
        ListNode* newHead = mergeList(left, right);
        return newHead;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slowPrevious = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr) {
            slowPrevious = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
		
		//ex. [1, 2, 3, 4, nullptr] -> [1, 2, nullptr] [3, 4, nullptr] where, slowPrevious = 2, slow->val = 3, 
        if(slowPrevious!=nullptr) slowPrevious->next = nullptr;
        return slow;
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* newHead = new ListNode(0);
        ListNode* current = newHead;
        while(left!=nullptr && right!=nullptr) {
            if(left->val < right->val) {
                current->next = left;
                current = current->next;
                left = left->next;
            }
            else {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }
        
        if(left==nullptr) current->next = right;
        else current->next = left;
        return newHead->next;
    }
};


// /* priority_queue solution */
// //Time complexity O(nlogn)
// //Space Complexity O(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        ListNode* previous = nullptr;
        ListNode* current = head;
        
		
		// priority_queue contains {node val and node pointer}, in sorted manner (ascending order)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq; 
        while (current != nullptr) {
            pq.push({current->val, current});
            current = current->next;
        }
        
        ListNode* newHead = new ListNode(0);
        previous = newHead;
        
		// building linked list
        while (!pq.empty()) {
            current = pq.top().second;
            previous->next = current;
            previous = previous->next;
            pq.pop();
        }
		// next of last node of a linked list must be null pointer
        if(current!=nullptr) current->next = nullptr;
        
        return newHead->next;
    }
};


//Quicksort approach
//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution{
public:
    int getPivotIndex(ListNode* node,int index){
        while(index--){
            node=node->next;
        }
        return node->val;
    }
    int partitionFunction(ListNode* node, int low, int high){
        int pivot = getPivotIndex(node,high);
        for(int i=low;i<high;i++){
            if(node->val > pivot){
                swap(node->val,pivot);
            }
            node = node->next;
        }
        node->val=pivot;
        return high;
    }
    void quickSort(ListNode* head,int low, int high){
        if(low<high){
            int partitionIndex = partitionFunction(head,low,high);
            quickSort(head,low,partitionIndex-1);
            quickSort(head,partitionIndex+1,high);
            return;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        
        ListNode* newNode = head;
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        head = newNode;
        quickSort(head, 0, len-1);
        
        return newNode;
    }
};