//TC O(n)
//SC O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int c = 0 , d = 0;
        for(int i = 0; i < n; i++){
            if(islower(word[i])) c++;
            if(isupper(word[i])) d++;
        }
        if(c == n || d == n || ((word[0] >= 'A' && word[0] <= 'Z') && c==n-1)) return true;
        return false;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int Upper = 0;
        
        for(int i=0;i<n;++i)
            if(word[i]>='A' && word[i]<='Z')
                ++Upper;
        
        if(Upper==n or Upper==0 or (word[0]>='A' and word[0]<='Z' and Upper==1))
            return true;
        
        return false;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=1;i<word.size();i++){
            if( (isupper(word[1]) != isupper(word[i]))  ||  (islower(word[0]) && isupper(word[i])) )
                return false;
        }
        return true;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() < 2) return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i = 2; i < word.length(); i++){
                if(islower(word[i])) return false;
            }
        }
        else{
            for(int i = 1; i < word.length(); i++){
                if(isupper(word[i])) return false;
            }
        }
        return true;
    }
};