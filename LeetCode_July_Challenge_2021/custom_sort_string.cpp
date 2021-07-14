//Time complexity O(n)
//Space complexity O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        int chars[128];
        
        for(int i=0, lmt=order.size();i<lmt;i++){
            chars[order[i]]=i;
        }
        sort(begin(str),end(str), [&chars](char a,char b){return chars[a] < chars[b];});
        
        return str;
    }
};

//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string customSortString(string order, string str) {
        short freqs[128]={}, i=0;
        for(short i=0;i<str.size();i++){
            freqs[str[i]]++;
        }
        for(char c : order){
            while(freqs[c]--) str[i++]=c;
        }
        for(short c='a';c<='z';c++){
            if(freqs[c]>0){
                while(freqs[c]--) str[i++]=c;
            }
        }
        return str;
    }
};