class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue){
            ans++;
            if(target % 2 == 1){
                target++;
            }else{
                target/=2;
            }
            //cout << target <<endl;
        }
        //cout << target <<endl;
        return ans + startValue - target;
    }
};

// if(X >= Y)   return X - Y;
// if(Y % 2 == 0)  return brokenCalc(X, Y/2) + 1;
// return brokenCalc(X, Y+1) + 1;