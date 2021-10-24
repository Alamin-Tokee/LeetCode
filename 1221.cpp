class Solution {
public:
    int balancedStringSplit(string s) {
        int count1=0;
        int count2=0;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L'){
                count1++;
            }
            if(s[i]=='R'){
                count2++;
            }
            
            if(count1==count2) c++;
        }
        
        return c;
    }
};


class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char>st;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top()==s[i]) st.push(s[i]);
                else st.pop();
                
                if(st.empty()) c++;
            }
        }
        return c;
    }
};