//First Approach

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int node = 1;
        while(getline(ss, curr, ',')){
            node--;
            if(node < 0) return false;
            if(curr != "#") node+=2;
        }
      
        return node==0;
    }
};

//Second Approach
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int a=0,b=0;
        for(int i=0;i<preorder.length();i++){
            if(b>a) return false;
            
            if(preorder[i]=='#'){
                b++;
            }
            else{
                a++;
            }
            
            while(i<preorder.length() && preorder[i]!=',') i++;
        }
        return a==b-1;
    }
};

//Third Approach
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int node=1;
        for(int i=0;i<preorder.length();i++){
            if(preorder[i]==',') continue;
            node--;
            if(node < 0) return false;
            if(preorder[i]!='#'){
                node+=2;
                while(i < preorder.length() && preorder[i]>='0' && preorder[i]<='9') i++;
            }
        }
        
        return node==0;
    }
};