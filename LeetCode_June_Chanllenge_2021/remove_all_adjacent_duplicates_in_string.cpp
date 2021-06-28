class Solution {
public:
    string removeDuplicates(string s) {
         string res="";
         for(char c:s){
             if(!res.empty() && res.back()==c){
                 res.pop_back();
             }else{
                 res.push_back(c);
             } 
                 
         }
        return res;
   }
};


class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        deque<char> dq;
        int i=0;
        while(i<n){
            if(dq.empty() || dq.back()!=s[i]){
                dq.push_back(s[i]);
                i++;
            }else {
                dq.pop_back();
                i++;
            }
        }
        string res="";
        while(!dq.empty()){
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        return res;
    }
};