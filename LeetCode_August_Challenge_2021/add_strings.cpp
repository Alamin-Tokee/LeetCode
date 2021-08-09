//First Solution
//Time Complexity O(m+n)
//Space Complexity O(1)

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int n1=num1.size()-1,n2=num2.size()-1,carry = 0;
        while(n1 >= 0 || n2 >= 0 || carry ){
            
            if( n1 >= 0 ){
                carry+=num1[n1]-'0';
                n1--;
            }
            if( n2 >= 0 ){
                carry+=num2[n2]-'0';
                n2--;
            }
            
            ans+=char(carry%10+'0');
            carry/=10;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};


// First Solution
// Time Complexity O(m+n)
// Space Complexity O(1)
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans="";
        int carry=0;
        
        if(num1.size() > num2.size()) swap(num1,num2);
        while(num1.size() < num2.size()){
            num1+='0';
        }
        for(int i=0;i<num1.length();i++){
            int curr=num1[i]-'0'+num2[i]-'0'+carry;
            ans+=(curr%10)+'0';
            carry=curr/10;
        }
        
        if(carry){
            ans+=(carry+'0');
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};