class Solution {
public:
    int checkWord(string& w,string& v){
        int foundChar=0;
        for(char& c:w){
            if(v.find(c)!=string::npos){
                foundChar++;
            }
        }
        return foundChar;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string>value={"QqWwEeRrTtYyUuIiOoPp","AaSsDdFfGgHhJjKkLl","ZzXxCcVvBbNnMm"};
        vector<string>ans;
        for(auto &w:words){
            for(auto &v:value){
                int found=checkWord(w,v);
                if(found==0) continue;
                if(found < w.size()) break;
                if(found==w.size()) ans.push_back(w);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int checkWord(string& w,string& v){
        int foundChar=0;
        for(char& c:w){
            if(v.find(c)!=string::npos){
                foundChar++;
            }
        }
        return foundChar;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string>value={"QqWwEeRrTtYyUuIiOoPp","AaSsDdFfGgHhJjKkLl","ZzXxCcVvBbNnMm"};
        vector<string>ans;
        for(auto &w:words){
            for(auto &v:value){
                int found=checkWord(w,v);
                if(found==0) continue;
                if(found < w.size()) break;
                if(found==w.size()) ans.push_back(w);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> m;
        
        string s1 = "qwertyuiopQWERTYUIOP";
        string s2 = "asdfghjklASDFGHJKL";
        string s3 = "zxcvbnmZXCVBNM";
        
        for(char c:s1) m.insert({c,1});
        for(char c:s2) m.insert({c,2});
        for(char c:s3) m.insert({c,3});
        
        for(string s: words){
            bool flag = true;
            int check = m[s[0]];
            
            for(int i = 0; i<s.size(); i++){
                if(m[s[i]]!=check){
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(s);
        }
        
        return ans;
    }
};


vector<string> findWords(vector<string>& words) {
	int A['z' + 1]{};
	string firstRow = "qwertyuiopQWERTYUIOP";
	string secondRow = "asdfghjklASDFGHJKL";
	string thridRow = "zxcvbnmZXCVBNM";
	for (char ch : firstRow) A[ch] = 1;
	for (char ch : secondRow) A[ch] = 2;
	for (char ch : thridRow) A[ch] = 3;
	vector<string> res{};
	for (string& word : words) {
		bool inOneRow = true;
		int row{ A[word[0]] };
		for (char ch : word) {
			if (A[ch] != row) {
				inOneRow = false;
				break;
			}
		}
		if (inOneRow)
			res.push_back(word);
	}
	return res;
}