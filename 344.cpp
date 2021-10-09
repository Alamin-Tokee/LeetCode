class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        while(i<n/2){
            swap(s[i],s[n-i-1]);
            i++;
        }
    }
};