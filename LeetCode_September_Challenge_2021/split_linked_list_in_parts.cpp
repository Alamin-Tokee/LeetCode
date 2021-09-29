/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Approach 1
class Solution {
public:
    vector<ListNode*> split(ListNode *head,int base_len,int rem){
        vector<ListNode*>ans;
        
        while(head!=NULL){
            ans.push_back(head);
            int total{base_len};
            if(rem > 0){
                total++;
                rem--;
            }
            while(total>1){
                head=head->next;
                total--;
            }
            ListNode *temp=head->next;
            head->next=NULL;
            head=temp;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node=head;
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node=node->next;
        }
        int div=cnt/k;
        int mod=cnt%k;
        vector<ListNode*>ans;
        
        if(cnt < k) ans=split(head,1,0);
        else ans=split(head,div,mod);
        
        if(cnt < k){
            int n=k-cnt;
            while(n--){
                ans.push_back(NULL);
            }
        }
        
        return ans;
    }
};


//Approach 2
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node=head;
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node=node->next;
        }
        int div=cnt/k;
        int mod=cnt%k;
        vector<ListNode*>ans(k,NULL);
        
        ListNode* nod=head;
        ListNode* prev=NULL;
        int i=0;
        while( nod!=NULL && i < k){
            ans[i]=nod;
            
            for(int j=0;j<div+(mod>0?1:0);j++){
                prev=nod;
                nod=nod->next;
            }
            prev->next=NULL;
            i++;
            mod--;
        }
        
        return ans;
    }
};