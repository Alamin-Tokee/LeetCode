class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.length();
        string str="";
        for(int i=0;i<len;i++){
            if(isalnum(s[i])){
                str+=tolower(s[i]);
            }
        }
        int l=0, r=str.length()-1;
        while(l<r){
            if(str[l++]!=str[r--]){
                return false;
            }
        }
        return true;
    }
};