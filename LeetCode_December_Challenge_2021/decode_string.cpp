//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
private:
    string decodeString(string& s,int &i){
        string result;
        while(i < s.length() && s[i] != ']'){
            if(isdigit(s[i])){
                int k=0;
                while(i < s.length() && isdigit(s[i]))
                    k = k * 10 + (s[i++]-'0');
                i++;
                string r = decodeString(s,i);
                while(k-- > 0)
                    result += r;
                i++;
            }else{
                result+=s[i++];
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        int i=0;
        
        return decodeString(s,i);
    }
};


//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string decodeString(string s) {
        stack<int>cntStack;
        stack<string>strStack;
        int cnt = 0;
        string str;
        for(auto& c:s){
            if(c >= '0' and c <= '9') cnt = cnt * 10 + (c-'0');
            else if(c == '['){
                cntStack.push(cnt);
                strStack.push(str);
                cnt = 0 ; str.clear();
            }else if(c == ']'){
                int k = cntStack.top(); cntStack.pop();
                while(k--) strStack.top() += str;
                str = strStack.top(); strStack.pop();
            }else{
                str += c;
            }
        }
        return str;
    }
};