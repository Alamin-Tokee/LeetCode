//TC O(n)
//SC O(n)
class Solution {
public:
     string removeKdigits(string num, int k) {
        string ans="";
        for(auto &i:num)
        {
            while(ans.size() && ans.back()>i && k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size() || i!='0')ans.push_back(i);
        }
        while(k-- && ans.size())ans.pop_back();
        return ans.size()?ans:"0";
    }
};
