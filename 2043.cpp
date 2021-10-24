class Bank {
    vector<long long> balance;
    bool valid(int account) {
        return account > 0 && account <= balance.size();
    }
    bool enough(int account, long long money) {
        return balance[account - 1] >= money;
    }
    
    // bool transfer(int from, int to, long long money) {
    //     return valid(to) && withdraw(from, money) && deposit(to, money);
    // }
public:
    // Bank(vector<long long>& balance) : balance(balance) {}
    Bank(vector<long long>& balance){
        this->balance=balance;
    }
    bool transfer(int from, int to, long long money) {
        if (valid(from) && valid(to) && enough(from, money)) {
            balance[from - 1] -= money;
            balance[to - 1] += money;
            return true;
        }
        return false;
    }
    bool deposit(int account, long long money) {
        if (valid(account)) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }
    bool withdraw(int account, long long money) {
        if (valid(account) && enough(account, money)) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};



class Bank {
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > bal.size() || account2 > bal.size())
            return false;
        if(bal[account1-1] < money )
            return false;
        
        bal[account1-1] -= money;
        bal[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > bal.size())
            return false;
        
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > bal.size())
            return false;
        if(bal[account-1] < money)
            return false;
        
        bal[account-1] -= money;
        return true;
    }
};