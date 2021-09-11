//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int>st;
        int result=0,sign=1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int num=s[i]-'0';
                while(i+1<n && isdigit(s[i+1]))
                    num=num*10+(s[++i]-'0');
                result+=num*sign;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]==')'){
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
        }
        return result;
    }
};