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


//Quick sort 
//Time complexity O(nlogn)
//Space complexity O(1)

class Solution {
public:
    int partition(vector<int>& v,string &str,int l,int r){
        int i=l-1;
        int pivot=v[str[r]-'a'];
        for(int j=l;j<r;j++){
            if(v[str[j]-'a'] < pivot){
                i++;
                swap(str[i],str[j]);
            }
        }
        i++;
        swap(str[i],str[r]);
        return i;
    }
    void quickSort(vector<int>& v,string &str,int l,int r){
        if(l>=r) return;
        
        int p=partition(v,str,l,r);
        
        quickSort(v,str,l,p-1);
        quickSort(v,str,p+1,r);
    }
    string customSortString(string order, string str) {
        int n=order.size();
        vector<int>v(26,n);
        for(int i=0;i<n;i++){
            v[order[i]-'a']=i;
        }
        
        quickSort(v,str,0,str.size()-1);
        
        return str;
    }
};