class Solution {
public:
    void findAllCombination(vector<string>&result,string digits,string current,int ind,vector<string>&mapping){
        if(ind==digits.length()){
            result.push_back(current);
            return;
        }
        string letters=mapping[digits[ind]-'0'];
        for(int i=0;i<letters.length();i++){
            findAllCombination(result,digits,current+letters[i],ind+1,mapping);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "" || digits.length() == 0) {
            return {};
        }
        vector<string>result;
        vector<string>mapping {"0","1","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        findAllCombination(result,digits,"",0,mapping);
        return result;
    }
};