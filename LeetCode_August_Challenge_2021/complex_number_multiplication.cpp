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


//Intution Procee Without Library
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        //from the string we must extract the real and imaginary parts to perform individual multiplication.
        string r1 = "", r2 = "", img1 = "", img2 = "";
        int f = 0;
        for(int i = 0; i < num1.size(); i++){
            if(num1[i] == '+')
                f = 1;
            
            if(f and num1[i] != '+' and num1[i] != 'i')
                img1 += num1[i];
            else if(f == 0)
                r1 += num1[i];        
        }
        f = 0;
        for(int i = 0; i < num2.size(); i++){
            if(num2[i] == '+')
                f = 1;
            
            if(f and num2[i] != '+' and num2[i] != 'i')
                img2 += num2[i];
            else if(f == 0)
                r2 += num2[i];        
        }
        
        
        //stoi function is used to convert small integers directly to string
        int real1 = stoi(r1);
        int real2 = stoi(r2);
        int imaginary1 = stoi(img1);
        int imaginary2 = stoi(img2);
        
        //This way we tend to extract the real and imaginary parts in integer from their respective strings.
        
        string ans = "";
        //Now, mathematically the real part equals to
        ans += to_string((real1 * real2) - (imaginary1 * imaginary2));
        
        ans += '+';
        
        //Now, mathematically the imaginary part equals to
        ans += to_string((real1 * imaginary2) + (real2 * imaginary1));
        ans += 'i';
        
        return ans;
    }
};