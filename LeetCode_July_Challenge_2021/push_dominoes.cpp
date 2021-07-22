class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>left(n,0),right(n,0);
        char prev= '.';
        int count = 1;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'L'){
                prev = 'L';
            }
            
            if(prev == 'R' && dominoes[i] == '.'){
                right[i] = count;
                count++;
            }
        }
        prev = '.';
        count = 1;
        for(int i = n-1; i >= 0; i--){
            if(dominoes[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'R'){
                prev = 'R';
            }
            
            if(prev == 'L' && dominoes[i] == '.'){
                left[i] = count;
                count++;
            }
        }
        string finalResult = "";
        for(int i=0;i<n;i++){
            if(left[i] == 0 && right[i] == 0){
                finalResult += dominoes[i];
            }
            
            else if(left[i] == 0){
                finalResult += 'R';
            }
            
            else if(right[i] == 0){
                finalResult += 'L';
            }
            
            else if(left[i] == right[i]){
                finalResult += '.';
            }
            else if(left[i] > right[i]){
                finalResult += 'R';
            }
            else{
                finalResult += 'L';
            }
        }
        return finalResult;
    }
};


//Sollution
class Solution {
public:
    string pushDominoes(string s) {
        if(s.size() == 1)
            return s;
        string fans = "";
        while(1){
            string ans = "";
            for(int i = 0; i < s.size(); i++){
                if(i == 0){
                    if(s[i] == '.' and s[i + 1] == 'L') ans += s[i + 1];
                    else ans += s[i];
                }
                else if(i == s.size() - 1){
                    if(s[i] == '.' and s[i - 1] == 'R') ans += s[i - 1];
                    else ans += s[i];
                }
                else{
                    if(s[i] == '.' and s[i - 1] == 'R' and s[i + 1] != 'L') ans += s[i - 1];
                    else if(s[i] == '.' and s[i + 1] == 'L' and s[i - 1] != 'R') ans += s[i + 1];
                    else ans += s[i];
                }
            }
            s = ans;
            if(s == fans) break;
            else fans = s; 
        }
        return fans;
    }
};
//Solution II:

#define ll long long int
class Solution {
public:
    string pushDominoes(string s) {
        ll n = s.size();
        if(n == 1)
            return s;
        vector<ll> r(n), l(n);
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') r[i] = 1;
            else if(s[i] == '.' and i > 0){
                if(r[i - 1] != INT_MAX) r[i] = r[i - 1] + 1;
                else r[i] = INT_MAX;
            }
            else r[i] = INT_MAX;     
        }
        
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'L') l[i] = 1;
            else if(s[i] == '.' and i < n - 1){
                if(l[i + 1] != INT_MAX) l[i] = l[i + 1] + 1;
                else l[i] = INT_MAX;
            }
            else l[i] = INT_MAX;
        }
        
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
                if(l[i] == r[i]) ans += '.';
                else if(l[i] < r[i]) ans += 'L';
                else if(l[i] > r[i]) ans += 'R';
            }
            else ans += s[i];
        }
        return ans;
    }
};