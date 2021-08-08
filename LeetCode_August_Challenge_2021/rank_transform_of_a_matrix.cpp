//Solution One
class Solution {
public:
    int find_set(int x,vector<int>& parent){
        if(parent[x]==x)
            return x;
        return parent[x] = find_set(parent[x],parent);
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        map<int,vector<pair<int,int>>> ele;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ele[mat[i][j]].push_back({i,j}); // put same value element in same vector
        }
 
        vector<int> rank(n+m,0); // rank of rows and columns
        for(auto itr:ele){
            vector<int> parent(n+m,0); // parent vector
            for(int i=0;i<parent.size();i++)
                parent[i] = i;
            for(auto it:itr.second){
                int i = it.first,j = it.second;
                int xroot = find_set(i,parent),yroot = find_set(j+n,parent); // find parent's
                parent[xroot] = yroot; // union, make row point to same column
                rank[yroot] = max(rank[xroot],rank[yroot]); // find maximum rank over this connected component
            }
            vector<int> curr = rank;
            // assign each cell, correct rank
            for(auto it:itr.second){
                int i = it.first,j = it.second;
                int r = find_set(i,parent);
                ans[i][j] = 1 + rank[r];
                curr[i] = rank[r] + 1;
                curr[j+n] = rank[r] + 1;
            }
            swap(rank,curr);
        }
        return ans;
    }
};

//Solution Two
class Solution {
public:
    
#define lop(i,s,e)                                  for(int i=s;i<(int)e;i++)
#define pii                                         pair<int,int>
#define ff                                          first
#define ss                                          second

    pii par[501][501];                          // par[i][j] -> parent of cell {i, j}
    int sz[501][501];                           // sz[i][j] -> size of set whose leader/parent is {i, j}
    
    // DSU IMPLEMENTATION below
    // void build(int n, int m);               // Initialising DSU
    // pii find(pii a) ;                      // Finding leader/parent of cell {i, j}
    // void make_union(pii a, pii b);        // Uniting 2 cells 
    
     vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector < vector<int> > ans(n, vector<int> (m, -1) );
        
        // Initialising DSU
        build(n, m);
        
        // Uniting All cells with rank value in same row
        lop(i, 0, n){
            map<int, pii> mp;
            lop(j, 0, m){
                int val = mat[i][j];
                if( mp.count( val ) ) make_union( {i,j} , mp[val]);
                mp[val] = {i, j};
            }
        }
        
        // Uniting all cells with rank value in same column
        lop(j, 0, m){
            map<int, pii> mp;
            lop(i, 0, n){
                int val = mat[i][j];
                if( mp.count( val ) ) make_union( {i,j} , mp[val]);
                mp[val] = {i, j};
            }
        }
        
        
        // Keeping cells with same rank in a vector of their parent/leader
        vector<pii> all[n][m];
        lop(i, 0, n)lop(j, 0, m){
            pii x = {i, j};
            pii p = find(x);
            all[p.ff][p.ss].push_back( x );
        }
        
        // Storing vectors in a map  with their parent value as key
        map<int, vector< vector<pii> > > mp;
        lop(i, 0, n){
            lop(j,0,m){
                if( (int)all[i][j].size() == 0 ) continue;
                int val = mat[i][j];
                mp[ val ].push_back( all[i][j] );
            }
        }
        vector<int> row(n, 0), col(m, 0);
         
        // row[i] = largest rank till now in ith row
        // col[i] = largest rank till now in ith column
         

        for(auto &i: mp){   // first assigning ranks to smaller elements then larger elements
            
            for(auto &j: i.ss){ 
                
                // x -> answer for current vector of cells ( all these cells will get the same rank )
                int x = 0;
                
                for(auto &k: j){
                    int r = k.ff, c = k.ss;         // {r,c} -> current cell
                    
                    // ans should be >= max(row[r], row[c]) + 1 ,
                    // because largest rank of smaller elements in this row/column is == max(row[r], row[c])
                    
                    x = max(x,  max(row[r], col[c]) + 1 );
                }
                
                for(auto &k: j){
                    int r = k.ff, c = k.ss;
                    ans[r][c] = x;
                   
                    // Updating largest rank in row and column for the current row and column
                    row[r] = max(row[r], x);
                    col[c] = max(col[c], x);
                }
            }
        }

        return ans;
    }
    
    /// DSU IMPLEMENTATION
    void build(int n, int m) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                par[i][j] = {i, j};
                sz[i][j] = 1;
            }
        }
    }

    pii find(pii a) {                   // finding leader/parent of cell {i, j}
        if( par[a.ff][a.ss] == a) return a;
        return par[a.ff][a.ss] = find( par[a.ff][a.ss] );
    }

    void make_union(pii a, pii b) {         // Uniting 2 cells 
        pii pa = find(a), pb = find(b);

        if( pa != pb ) {
            if( sz[pa.ff][pa.ss] < sz[pb.ff][pb.ss] ) swap(pa,pb);
            par[pb.ff][pb.ss] = pa;
            sz[pa.ff][pa.ss] += sz[pb.ff][pb.ss];
        }
    }

    
};