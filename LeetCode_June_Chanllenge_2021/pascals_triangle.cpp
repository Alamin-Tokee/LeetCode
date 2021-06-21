//Aproach 1

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        for(int i=0;i<numRows;i++){
            vec.push_back(vector<int>());
            for(int j=0;j<=i;j++){
                if(j==0){
                    vec[i].push_back(1);
                }
                else if(i==j){
                    vec[i].push_back(1);
                }
                else{
                    vec[i].push_back(vec[i-1][j]+vec[i-1][j-1]);
                }
            }
        }
        return vec;
    }
};

//Aproach 2

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        vector<int>res;
        vec.push_back({1});
        if(numRows==1) return vec;
             
        vec.push_back({1,1});
    
        for(int i=2;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0) res.push_back(1);
                else if(j==i) res.push_back(1);
                else{
                    res.push_back(vec[i-1][j-1]+vec[i-1][j]);
                }
            }
            vec.push_back(res);
            res.clear();
        }
        
        return vec;
    }
};


//Math Formula
class Solution {
public:
    vector<int> getRow(int line) {
        int prev = 1;
        vector<int> temp{1};
        for(int i = 1; i<line+1; i++) {
            int curr = ((line-i+1) * prev)/i;
            temp.push_back(curr);
            prev = curr;
        }
        return temp;
    }
    
    vector<vector<int>> generate(int line) {
        vector<vector<int>> result;
        result.push_back({1});
        if(line == 1) {
            return result;
        }
        
        for(int lineNo = 1; lineNo < line; lineNo++) {
            result.push_back(getRow(lineNo));
        }
        
        return result;
    }
};