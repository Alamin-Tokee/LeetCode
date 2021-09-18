//Iterative Solution

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int sum=0;
        sum=numBottles;
        //sum+=numBottles/numExchange;
        
        while(numBottles >= numExchange){
            int extra=numBottles%numExchange;
            numBottles=numBottles/numExchange;
            sum+=numBottles;
            numBottles+=extra;
        }
        return sum;
    }
};

//Recursive Solution
class Solution {
public:  
    int countbottles(int filled, int empty, int rate)
    {
        if ((filled+empty)/rate == 0 )
            return filled;
        
        return filled + countbottles((filled+empty)/rate, (filled+empty)%rate, rate);
    }
    int numWaterBottles(int numBottles, int numExchange)
    {
        return numBottles + countbottles(numBottles/numExchange, numBottles%numExchange, numExchange) ;
    }
};