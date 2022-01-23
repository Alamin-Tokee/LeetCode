class Solution {
public:
    vector<int> ans;
    void dfs(int low,int high,int i, int num){
        if(num >= low and num <= high) ans.push_back(num);
        if(num > high or i > 9) return;
        dfs(low, high, i+1, num*10+i);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++)
            dfs(low, high, i, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
         vector<int> allnumbers ={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
        
        int start = lower_bound(allnumbers.begin() , allnumbers.end() , low) - allnumbers.begin();
        int end = upper_bound(allnumbers.begin() , allnumbers.end() , high) - allnumbers.begin();
        
        vector<int> res;
        
        for(int i = start ; i< end; i++){
            res.push_back(allnumbers[i]);
        }
        
        return res;
    }
};

class Solution{
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int num = 0;
        for(int i = 1;i<10;i++){
            num = i;
            for(int j = i + 1;j < 10;j++){
                num = num * 10 + j;
                if(num >= low && num <= high ){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution{
    public:
    int numLen(int digit){
        int count = 0;
        
        while(digit != 0){
            count++;
            digit = digit/10;
        }
        
        return count;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        int n = digits.size();
        
        int lowLen = numLen(low);//calculate the len of digits to create a window 
        int hiLen = numLen(high);
        vector<int>ans;
        
        for(int i=lowLen;i<=hiLen;i++){
            for(int j=0;j<=(n-i);j++){
                int num = stoi(digits.substr(j,i));//taking the substring of current window size  and converting to integer
                if(num>=low and num<=high)//checking the limits
                    ans.push_back(num);
            }
        }
        
        return ans;
    }
};