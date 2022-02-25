//TC O(n)
//SC O(n)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        vector<string>num1, num2;
        string c1 = "";
        for(auto&x: version1)
            x=='.'? num1.push_back(c1),c1="" :  c1+=x;
        num1.push_back(c1); c1="";
            
        for(auto&x: version2)
            x=='.'? num2.push_back(c1),c1="" :  c1+=x;
        num2.push_back(c1);

        int i = 0, j = 0;
        while(i < num1.size() && j < num2.size()){
            int n1 = stoi(num1[i]);
            int n2 = stoi(num2[i]);
            if(n1 < n2) return -1;
            else if(n1 > n2) return 1;
            i++;j++;
        }
        
        while(i < num1.size()){
            int n1 = stoi(num1[i]);
            if(n1 > 0) return 1;
            i++;
        }
        
        while(j < num2.size()){
            int n2 = stoi(num2[j]);
            if(n2 > 0) return -1;
            j++;
        }
        
        return 0;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        
        int num1 = 0 , num2 = 0;
        while(i < n1 || j < n2){
            while(i < n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }
            while(j < n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0');
                j++;
            }
            
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = num2 = 0;
            
            i++; j++;
        }
        return 0;
    }
};

//TC O(n)
//SC O(n)
class Solution {
public:
    vector<string> split(string s, char delim){
        vector<string> res;
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim)){
            res.push_back(item);
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = split(version1, '.');
        vector<string>v2 = split(version2, '.');
        int i = 0, j = 0;
        while(i<v1.size() && j<v2.size()){
            int n1 = stoi(v1[i]);
            int n2 = stoi(v2[j]);
            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;
            i++;j++;
        }
        while(i < v1.size()){
            int n1 = stoi(v1[i]);
            if(n1 > 0) return 1;
            i++;
        }
        while(j < v2.size()){
            int n2 = stoi(v2[j]);
            if(n2 > 0) return -1;
            j++;
        }
        return 0;
    }
};