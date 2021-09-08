
//Brute Force (TLE)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int ch=((s[j]-'a')+shifts[i])%26;
                s[j]=ch+'a';
            }
        }
        return s;
    }
};
//With Extra Space
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
         int n=shifts.size();
    
         vector<int>suffix(n,0);
    
         suffix[n-1]=shifts[n-1];
    
         for(int i=n-2;i>=0;i--){
             suffix[i]=(shifts[i]+suffix[i+1])%26;
         }
           
        string res="";
        for(int i=0;i<s.length();i++){
            int val=((s[i]-'a')+suffix[i])%26;
            char ch=val+'a';
            res+=ch;
        }
        return res;
    }
};

//Without Extra Space 
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
         int n=shifts.size();
    
         for(int i=n-2;i>=0;i--){
             shifts[i]=(shifts[i]+shifts[i+1])%26;
         }
    
        string res="";
        for(int i=0;i<s.length();i++){
            int val=((s[i]-'a')+shifts[i])%26;
            char ch=val+'a';
            res+=ch;
        }
        return res;
    }
};


    