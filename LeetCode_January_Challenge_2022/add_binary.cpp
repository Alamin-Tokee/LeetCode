//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,carry = 0;
        string sum = "";
        while(i>=0 || j>=0 || carry==1){
            carry += i>=0 ? a[i--]-'0':0;
            carry += j>=0 ? b[j--]-'0':0;
            sum=char(carry%2+'0') + sum;
            carry/=2;
        }
        return sum;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int carry =0;
        int n=a.size();
        int m=b.size();
        string res="";
        while(n>=1 & m>=1){
            int num=(a[n-1]-'0')+(b[m-1]-'0')+carry;
            if(num==0 || num==1){
                res=to_string(num)+res;
                carry=0;
            }else if(num==2){
                res='0'+res;
                carry=1;
            }else{
                res='1'+res;
                carry=1;
            }
            n--; m--;
        }
        while(n){
            int num=(a[n-1]-'0')+carry;
            if(num==0 || num==1){
                res=to_string(num)+res;
                carry=0;
            }else if(num==2){
                res='0'+res;
                carry=1;
            }else{
                res='1'+res;
                carry=1;
            }
            n--;
        }
        while(m){
            int num=(b[m-1]-'0')+carry;
            if(num==0 || num==1){
                res=to_string(num)+res;
                carry=0;
            }else if(num==2){
                res='0'+res;
                carry=1;
            }else{
                res='1'+res;
                carry=1;
            }
            m--;
        }
        if(carry==1) res='1'+res;
        
        return res;
    }
};