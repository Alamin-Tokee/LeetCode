class Solution {
public:
    unordered_set<string>visited;
    unordered_map<string,vector<string>>ad;
    void DFS(vector<string>&merge,string& email){
        visited.insert(email);
        merge.push_back(email);
        for(string& neighbor : ad[email]){
            if(visited.find(neighbor)==visited.end()){
                DFS(merge,neighbor);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountSize=accounts.size();
        for(vector<string>& account:accounts){
            int accountSize=account.size();
            string accountFirstEmail=account[1];
            for(int i=2;i<account.size();i++){
                string email=account[i];
                ad[accountFirstEmail].push_back(email);
                ad[email].push_back(accountFirstEmail);
            }
        }
        
        vector<vector<string>>mergeAccount;
        for(vector<string>& account:accounts){
            string accountName=account[0];
            string accountFirstEmail=account[1];
            if(visited.find(accountFirstEmail)==visited.end()){
                vector<string>merge;
                merge.push_back(accountName);
                DFS(merge,accountFirstEmail);
                sort(merge.begin()+1,merge.end());
                mergeAccount.push_back(merge);
            }
        }
        return mergeAccount;
    }
};


class DSU{
public:
    vector<int>representParent;
    vector<int>rank;

    DSU(int sz): representParent(sz), rank(sz){
        for(int i=0;i<sz;i++){
            representParent[i]=i;
            rank[i]=i;
        }
    }
    int findrepresentParent(int x){
        if(representParent[x]==x) return x;
        return representParent[x]=findrepresentParent(representParent[x]);
    }
    void unionRepresentParent(int u,int v){
        int representX=findrepresentParent(u);
        int representY=findrepresentParent(v);
        
        if(representX==representY) return;
        
        // if(representX >= representY){
        //     rank[representX]+=rank[representY];
        //     representParent[representY]=representX;
        // }else{
        //     rank[representY]+=rank[representX];
        //     representParent[representX]=representY;
        // }
        
        if(representX > representY){
            representParent[representY]=representX;
        }else if(representX < representY){
            representParent[representX]=representY;
        }else{
            representParent[representX]=representY;
            rank[representX]++;
        }
        
        // if(representX != representY){
        //     representParent[representY]=representX;
        // }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountListSize=accounts.size();
        DSU dsu(accountListSize);
        unordered_map<string,int>emailGroup;
        for(int i=0;i<accountListSize;i++){
            int accountSize=accounts[i].size();
            for(int j=1;j<accountSize;j++){
                string email=accounts[i][j];
                
                if(emailGroup.find(email)==emailGroup.end()){
                    emailGroup[email]=i;
                }else{
                    dsu.unionRepresentParent(i,emailGroup[email]);
                }
            }
        }
        
        unordered_map<int,vector<string>>components;
        for(auto emailIterator:emailGroup){
            string email=emailIterator.first;
            int group=emailIterator.second;
            components[dsu.findrepresentParent(group)].push_back(email);
        }
        vector<vector<string>>mergedAccount;
        for(auto componentIterator:components){
            int group=componentIterator.first;
            vector<string>component={accounts[group][0]};
            component.insert(component.end(),componentIterator.second.begin(),componentIterator.second.end());
            sort(component.begin()+1,component.end());
            mergedAccount.push_back(component);
        }
        return mergedAccount;
    }
};
