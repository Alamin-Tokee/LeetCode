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

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return f(s, i);
    }
int f(string s, int &i)
{
    long long val = 0, res = 0;
    int sign = 1;

    while (i < s.size() && s[i] != ')')
    {
        if (isspace(s[i]))
            i++;
        else if (isdigit(s[i]))
        {
            val = 0;
            while (i < s.size() && isdigit(s[i]))
                val = val * 10 + s[i++] - '0';

            res += val * sign;
        }
        else if (s[i] == '+' || s[i] == '-')
            sign = (s[i++] == '+') ? 1 : -1;
        else if (s[i] == '(')
        {
            i++;  // Move past '('
            int temp = f(s, i);
            i++;  // Move past ')'

            res += temp * sign;
        }
    }

    return res;
}
};