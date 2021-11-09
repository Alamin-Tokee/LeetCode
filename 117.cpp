class Solution {
public:
    Node* findNext(Node* root){
        if(!root) return NULL;
        if(root->left) return root->left;
        if(root->right) return root->right;
        
        return findNext(root->next);
    }
    void populateNext(Node* root){
        if(!root) return;
        
        if(root->left){
            root->left->next=root->right ? root->right : findNext(root->next);
        }
        if(root->right){
            root->right->next=findNext(root->next);
        }
        populateNext(root->right);
        populateNext(root->left);
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        populateNext(root);
        
        return root;
    }
};