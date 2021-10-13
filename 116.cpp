

class Solution {
public:
    void dfs(Node* root){
        if(!root) return;
        
        if(root->left){
            root->left->next=root->right;
        }
        if(root->right){
            if(root->next){
                root->right->next=root->next->left;
            }else{
                root->right->next=NULL;
            }
        }
         dfs(root->left);
         dfs(root->right);
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        root->next==NULL;
        dfs(root);
        
        return root;
    }
};


class Solution{
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            auto sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                
                if(i!=sz-1) x->next=q.front();
                else x->next=NULL;
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return root;
    }
};



class Solution{
public:
    void connect(Node* rleft, Node* rright){
        if (rleft == nullptr && rright == nullptr)
            return;
    
        rleft->next = rright;
        connect(rleft->left, rleft->right);
        connect(rleft->right, rright->left);
        connect(rright->left, rright->right);
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        connect(root->left,root->right);
        
        return root;
    }
};