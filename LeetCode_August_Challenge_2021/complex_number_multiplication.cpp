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
string complexNumberMultiply(string a, string b) {
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    sscanf(a.c_str(), "%d+%di",&a1,&b1);
    sscanf(b.c_str(), "%d+%di",&a2,&b2);
    return to_string(a1*a2-b1*b2)+"+"+to_string(a1*b2+a2*b1)+"i";
}

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

string complexNumberMultiply(string num1, string num2) {
    int a,b,c,d;
    //convert num1 to a+ib
    int it1=num1.find('+');
    a=stoi(num1.substr(0,it1));
    b=stoi(num1.substr(it1+1,num1.size()-2)); //num1.size()-2 to skip 'i' character at last index
    //convert num2 to c+ib
    int it2=num2.find('+');
    c=stoi(num2.substr(0,it2));
    d=stoi(num2.substr(it2+1,num2.size()-2));
    
    return to_string(a*c-b*d)+'+'+to_string(a*d+c*b)+'i';
}

//3rd Approach
class Solution {
public:
    complex<int> parse(string num) {
        int i = num.find('+');
        int real = stoi(num.substr(0, i));
        int imaginary = stoi(num.substr(i+1, num.size()-i-2));
        complex<int> res(real, imaginary);
        return res;
    }
    
    string complexNumberMultiply(string num1, string num2) {
        complex<int> a = parse(num1), b = parse(num2);
        complex<int> res = a * b;        
        
        return to_string(real(res)) + "+" + to_string(imag(res)) + "i";
    }
};

class Solution {
public:
    pair<int, int> parse(string num) {
        int i = num.find('+');
        double real = stoi(num.substr(0, i));
        double imaginary = stoi(num.substr(i+1, num.size()-i-2));
        pair<int, int> res(real, imaginary);
        return res;
    }
    
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> a = parse(num1), b = parse(num2);
        int real_a = a.first, imag_a = a.second;
        int real_b = b.first, imag_b = b.second;
        
        return to_string(real_a * real_b - imag_a * imag_b) + '+' + to_string(real_a * imag_b  + real_b * imag_a)+'i' ;
    }
};