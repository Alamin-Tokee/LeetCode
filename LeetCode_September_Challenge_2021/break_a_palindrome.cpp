//Approach 1
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1) return "";
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};

//Approach 2
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.length();
        if (length == 1) {
            return "";
        }
        for (int i = 0; i < length / 2; ++i) {
            if (palindrome.at(i) != 'a') {
                return palindrome.substr(0, i) + "a" + palindrome.substr(i + 1);
            }
        }
        return palindrome.substr(0, length - 1) + "b";
    }
};

//Approach 3
class Solution {
public:
  string breakPalindrome(string palindrome) {
    int n = palindrome.size(); 
    if(n == 1) return "";
    
    int lim = n>>1;
    for(int i = 0; i != lim; i++)                               
      if(palindrome[i] != 'a') {palindrome[i] = 'a'; return palindrome;}
    
    for(int i = lim + n%2; i != n; i++)                         
      if(palindrome[i] != 'a') {palindrome[i] = 'a'; return palindrome;}
    
    palindrome.back()++;                                        
    return palindrome;
  }
};

