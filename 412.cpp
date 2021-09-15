class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++){
            if(i%3==0 and i%5==0){
                v.push_back("FizzBuzz");
            }else if(i%3==0){
                v.push_back("Fizz");
            }else if(i%5==0){
                v.push_back("Buzz");
            }else{
                v.push_back(to_string(i));
            }
        }
        return v;
    }
};



//stringstream // >> extrats data from stream // << insert data int stream 
// stringstream ss;  
  // ss<<k;  
  // string s;  
  // ss>>s;


//string str= to_string(i);  

// string str = boost::lexical_cast<string>(i);  

//C 
//sprintf(text, "%d", number); 
//itoa(number,string,10);