//Iterative Approach
// Time complexity: O(2 ^ n)
// Space complexity: O(1)

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>result;
        int sequenceLength = 1 << n;
        
        for(int i=0;i< sequenceLength ; i++){
            int num= i ^ i >> 1;
            result.push_back(num);
        }
        
        return result;
    }
};

//Iterative Approach
// Time complexity: O(2 ^ n)
// Space complexity: O(n)
class Solution {
public:
    int nextNum=0;
    void grayCodeHelper(vector<int>& result,int n){
        if(n==0){
            result.push_back(nextNum);
            return;
        }
        grayCodeHelper(result,n-1);
        nextNum = nextNum ^ (1 << (n-1));
        grayCodeHelper(result,n-1);
        
    }
    vector<int> grayCode(int n) {
        vector<int>result;
        grayCodeHelper(result,n);
        
        return result;
    }
};


//Iterative Approach
// Time complexity: O(2 ^ n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        
        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.size();
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.push_back(mask + result[j]);
            }
        }
        return result;
    }
};