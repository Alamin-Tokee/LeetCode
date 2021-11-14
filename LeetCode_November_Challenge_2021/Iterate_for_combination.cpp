class CombinationIterator {
public:
    vector<string>v;
    int index=0;
    void combination(string& st,string c,int l,int s){
        if(c.size()==l){
            v.push_back(c);
            return;
        }
        for(int i=s;i<st.size();i++){
            c.push_back(st[i]);
            combination(st,c,l,i+1);
            c.pop_back();
        }
    }
    CombinationIterator(string ch, int l) {
        combination(ch,"",l,0);
    }
    
    string next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index < v.size();
    }
};