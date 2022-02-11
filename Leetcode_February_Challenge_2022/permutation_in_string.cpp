class Solution {
public:
    bool checkArrays(int A1[], int A2[]){
        for(int i=0; i<26; i++){
            if(A1[i] != A2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        int A1[26] = {0};
        int A2[26] = {0};
        
        if(l1 > l2) return false;
        
        for(int i=0; i<l1; i++){
            A1[s1[i] - 'a']++;
            A2[s2[i] - 'a']++;
        }
        
        // for(i=0; i<min(l1,l2); i++)
        //     arr2[s2[i] - 'a']++;
        
        if(checkArrays(A1, A2))
            return true;
        
        for(int i=0; i<l2-l1; i++){
            A2[s2[i] - 'a']--;
            A2[s2[i+l1] - 'a']++;
            if(checkArrays(A1,A2))
                return true;
        }
        
        return false;
    }
};



class Solution {
public:
    bool checkArrays(int A1[], int A2[]){
        for(int i=0; i<26; i++){
            if(A1[i] != A2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        int A1[26] = {0};
        int A2[26] = {0};
        for(int i=0; i<l1; i++){
            A1[s1[i]-'a']++;
        }
        
        for(int i=0; i<l2; i++){
            A2[s2[i]-'a']++;
            if(i>=l1){
                A2[s2[i-l1]-'a']--;
            }
            if(checkArrays(A1,A2))
                return true;
        }
        
        return false;
    }
};




class Solution {
public:
    bool checkEqual(vector<int>&f1,vector<int>&f2){
        for(int i=0;i<26;i++) if(f1[i]!=f2[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 > l2) return false;
        
        vector<int>freqS1(26, 0);
        for(auto c:s1) freqS1[c-'a']++;
        vector<int>freqS2(26, 0);
        int i = 0, j = 0;
        
        while(j < l2){
            freqS2[s2[j]-'a']++;
            if(j-i+1==l1) {
                if(checkEqual(freqS1,freqS2)) return true;
            }
            if(j-i+1 < l1) j++;
            else {
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};