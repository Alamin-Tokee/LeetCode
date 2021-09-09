//Time Complexity 4O(n^2)
//Space Complexity O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        for(auto it:mines){
            int x=it[0];
            int y=it[1];
            mat[x][y]=0;
        }
        vector<vector<int>>lef,rig,top,bot;
        lef=rig=top=bot=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=n-i-1;
                int y=n-j-1;
                if(i>0 && top[i][j]) top[i][j]+=top[i-1][j];
                if(j>0 && lef[i][j]) lef[i][j]+=lef[i][j-1];
                if(x<n-1 && bot[x][y]) bot[x][y]+=bot[x+1][y];
                if(y<n-1 && rig[x][y]) rig[x][y]+=rig[x][y+1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({lef[i][j],rig[i][j],top[i][j],bot[i][j]}));
            }
        }
        return ans;
    }
};


//Time Complexity 4O(n^2)(Another Approach)
//Space Complexity O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        for(auto it:mines){
            int x=it[0];
            int y=it[1];
            mat[x][y]=0;
        }
        vector<vector<int>>lef(n,vector<int>(n)),rig(n,vector<int>(n)),top(n,vector<int>(n)),bot(n,vector<int>(n));
        //left to right
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) runingSum=0;
                else runingSum+=mat[i][j];
                lef[i][j]=runingSum;
            }
        }
        //Right to Left
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==0) runingSum=0;
                else runingSum+=mat[i][j];
                rig[i][j]=runingSum;
            }
        }
        //Top to Bottom
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=0;j<n;j++){
                if(mat[j][i]==0) runingSum=0;
                else runingSum+=mat[j][i];
                top[j][i]=runingSum;
            }
        }
        //Bottom to Top
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=n-1;j>=0;j--){
                if(mat[j][i]==0) runingSum=0;
                else runingSum+=mat[j][i];
                bot[j][i]=runingSum;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({lef[i][j],rig[i][j],top[i][j],bot[i][j]}));
            }
        }
        return ans;
    }
};


class Solution {
public:
	// Time Complexity:- O(N^3) --> TLE (50/56 passed)
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n,vector<int>(n,1));
        for(auto v:mines){
            mat[v[0]][v[1]] = 0;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!mat[i][j])
                    continue;
                int curr = INT_MAX,index = i - 1;
                while(index>=0 and mat[index][j])
                    index--;
                curr = min(curr,i-index-1);
                index = i + 1;
                while(index<n and mat[index][j])
                    index++;
                curr = min(curr,index-i-1);
                index = j + 1;
                while(index<n and mat[i][index])
                    index++;
                curr = min(curr,index-j-1);
                index = j - 1;
                while(index>=0 and mat[i][index])
                    index--;
                curr = min(curr,j-index-1);
                ans = max(ans,1+curr);
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    // Time Complexity:- O(N^2LOG(N)) --> TLE (All passed but taken too long time)
    // Space Complexity:- O(N^2)
    
    // This function gives the minimum of length of two largest subarrays of +ve
    // starting on val, on both sides of val
    int get(vector<int>& v,int val){
        int end = lower_bound(v.begin(),v.end(),val) - v.begin();
        int start = upper_bound(v.begin(),v.end(),val) - v.begin() - 1;
        return min(v[end]-val-1,val-v[start]-1);
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<int> rows[n],cols[n]; // stores the position of zeroes for every row and columns
        for(auto c:mines){
            rows[c[0]].push_back(c[1]);
            cols[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            rows[i].push_back(-1); // push -1 , n to avoid checking corner cases
            rows[i].push_back(n);
            cols[i].push_back(-1);
            cols[i].push_back(n);
            sort(rows[i].begin(),rows[i].end()); // sort each rows and columns to perform binary search
            sort(cols[i].begin(),cols[i].end());
        }
        int ans = 0,r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ // maximise answer by considering every cell as the centre of plus sign
                r = get(rows[i],j);
                c = get(cols[j],i);
                ans = max(ans,1+min(r,c));
            }
        }
        return ans;
    }
};
