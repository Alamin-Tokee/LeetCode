//Time Complexity O(n)
//Space Complexiy O(n)

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        for(string email:emails){
            string mail="";
            for(char c:email){
                if(c=='+' || c=='@') break;
                if(c!='.') mail+=c;
            }
            
            mail+=email.substr(email.find('@'));
            st.insert(mail);
        }
        
        return st.size();
    }
};


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if (emails.empty())
            return 0;
        
        unordered_set<string> testSet;
        for (string email : emails) {
            auto separator_a = find(email.begin(), email.end(), '@');
            auto separator_plus = find(email.begin(), email.end(), '+');
            if (separator_plus != email.end() && separator_plus < separator_a) {
                email.erase(separator_plus, separator_a);
                separator_a = find(email.begin(), email.end(), '@');
            }
            for (auto it = email.begin(); it < separator_a;) {
                if (*it == '.')
                    it = email.erase(it);
                else
                    ++it;
            }
            testSet.insert(email);
        }
        return testSet.size();
    }
};


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        for(auto & email:emails)
        {
            int pos = email.find('@');
            string domain = email.substr(pos);
            string local_name=email.substr(0,pos);
            pos=local_name.find('+');
            if(pos!=string::npos)
               local_name.erase(pos);
            pos=-1;
            while((pos=local_name.find('.',pos+1))!=string::npos)
               local_name.erase(pos,1);
            unique_emails.insert(local_name+domain);
        }
        return unique_emails.size();
        
    }
};



class Solution{
    public:
    int numUniqueEmails(vector<string>& emails) {
    set<string>s;
    for(auto i:emails){
        string d=i;
        string temp;
    
        int x=0;
        for(x;d[x]!='@';x++){
            if(d[x]=='+'){
                break;
                
            }
            
            if(d[x]!='.'){
                temp.push_back(d[x]);
                
            }
        }
        while(d[x]!='@'){
            x++;
        }
        for(x;x<d.size();x++){
            temp.push_back(d[x]);
        }
     
        cout<<temp<<endl;
        s.insert(temp);
    }
    return s.size();
    
   }
};