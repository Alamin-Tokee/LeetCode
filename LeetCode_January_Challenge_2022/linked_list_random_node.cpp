//TC O(n)
//SC O(n)

class Solution {
public:
    map<int,int>m;
    int pos = 0;
    Solution(ListNode* head) {
        while(head != NULL){
            m[pos] = head->val;
            pos++;
            head=head->next;
        }
    }
    
    int getRandom() {
        int l = m.size();
        return m[rand()%l];
    }
};


class Solution {
public:
    vector<int> m;
    Solution(ListNode* head) {
        while(head != NULL){
            m.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int l = m.size();
        return m[rand()%l];
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    //Note : head is guaranteed to be not null, so it contains at least one node.
    ListNode* HeadNode;
    Solution(ListNode* head) {
       HeadNode = head;
    }
    //returns value of a random node
    int getRandom() {
        int res, len = 1;
        ListNode* x = HeadNode;
        while(x){
            if(rand() % len == 0){
                res = x->val;
            }
            len++;
            x = x->next;
        }
        return res;
    }
};
