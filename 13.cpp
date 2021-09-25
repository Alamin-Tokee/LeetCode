//Iterative Soltion

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(mp[s[i]] < mp[s[i+1]]){
                sum+=mp[s[i+1]]-mp[s[i]];
                i++;
                continue;
            }
            sum+=mp[s[i]];
        }
        return sum;
    }
};

//Using STL
class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> getVal = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0, val, prev = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            char c = *it;
            val = getVal[c];
            if (val >= prev) ans += val;
            else ans -= val;
            prev = val;
        }
        return ans;
    }
};


//Recusive Solution
class Solution {
    map<string, int> conv {
        { "M", 1000 },
        { "D", 500 },
        { "C", 100 },
        { "L", 50 },
        { "X", 10 },
        { "V", 5 },
        { "I", 1 },
        { "IV", 4 },
        { "IX", 9 },
        { "XL", 40 },
        { "XC", 90 },
        { "CD", 400 },
        { "CM", 900 },
        { "", 0 }
    };
    
public:
    int romanToInt(string s) {
        if (s.size() <= 1) return conv[s];
        string first_two = s.substr(0, 2);
        if (conv.count(first_two)) {
            return conv[first_two] + romanToInt(s.substr(2, s.size() - 2));
        }
        else {
            return conv[s.substr(0,1)] + romanToInt(s.substr(1, s.size() - 1));
        }
    }
};