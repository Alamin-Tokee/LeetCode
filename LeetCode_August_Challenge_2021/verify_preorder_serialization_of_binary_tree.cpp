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