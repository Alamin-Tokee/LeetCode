class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans="";
        string word="";
        while(ss >> word){
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        string word="";
        for(int i=0;i<n;i++){
            if(s[i]==' ' or i==n-1){
                if(i==n-1){
                    word+=s[i];
                }
                for(int k=0;k<word.size()/2;k++){
                    swap(word[k],word[word.size()-k-1]);
                }
                ans+=word;
                if(i!=n-1)ans+=" ";
                word="";
            }
            else {
                word+=s[i];
            }
        }
        return ans;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int n=s.size();
        
        int a=0;
        int b=0;
        int lastp=0;
        
        while(a<n)
        {
            b=a;
            while(s[b] !=' '){
                b++;
            }
            lastp=b;
            while(a<b){
                swap(s[a],s[b]);
                a++;
                b--;
            }
            a=lastp+1;          
        }
        s=s.substr(1,n);
        return s;
    }
};

