//Solution 1(StringStream)
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = 0, i1 = 0, r2 = 0, i2 = 0; 
        char buf;
        stringstream ss1(num1), ss2(num2), ans; 
        ss1 >> r1 >> buf >> i1 >> buf; 
        ss2 >> r2 >> buf >> i2 >> buf; 
        ans << r1*r2 - i1*i2 << "+" << r1*i2 + r2*i1 << "i"; 
        return ans.str();
    }
};