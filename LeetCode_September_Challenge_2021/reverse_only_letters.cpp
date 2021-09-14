
//Time Complexity O(n*n)
//Space Complexity O(n)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string r="";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                r+=s[i];
            }
        }
        reverse(r.begin(),r.end());
        int x=0,y=0;
        while(x < s.length()){
            if(isalpha(s[x])){
                s[x]=r[y];
                x++;
                y++;
            }else{
                x++;
            }
        }
        return s;
    }
};


//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int x=0,y=s.length()-1;
        while(x < y){
            if(isalpha(s[x]) && isalpha(s[y])){
                swap(s[x++],s[y--]);
            }else if(isalpha(s[x]) && !isalpha(s[y])){
                y--;
            }else{
                x++;
            }
        }
        return s;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
  string reverseOnlyLetters(string s) {
    int b = 0, e = s.size()-1;
    
    while(b < e){
      if( !((s[b] > 96 && s[b] < 123)|| (s[b] > 64 && s[b] < 91)) ) {b++;continue;}
      if( !((s[e] > 96 && s[e] < 123)|| (s[e] > 64 && s[e] < 91)) ) {e--;continue;}
      swap(s[b++], s[e--]);      
    }
    return s;
  }        
};