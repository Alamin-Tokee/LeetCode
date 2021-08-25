//TC O(logc)
//SC O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long int a = 0 ; a <= sqrt(c) ; a++)
        {
            double b = sqrt(c - a * a);
            if(b == (int)b)
            {
                return true ;
            }
        }
        return false ;
    }
};

//TC O(logc)
//SC O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 3)
            return true ;
        long long int a = 0 , b = sqrt(c) ;
        while(a <= b)
        {
            if(a*a + b*b == c)
            {
                return true ;
            }
            else if(a*a + b*b < c)
            {
                a++ ;
            }
            else
            {
                b-- ;
            }
        }
        return false ;
    }
};

//TC O(n)
//SC O(n)
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int,int> m;
        for(int i = 0;i <= 46340; i++){
            m[(i*i)]++;
            if(m.find(c - (i*i))!=m.end())return true;
        }
        return false;        
    }
};