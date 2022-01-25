//TC O(n)
//SC O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int m=A.size();
        int mi=INT_MIN;
        int k;
        bool flag=false;
        bool fla=false;
        if(m<3 || A[0]>=A[1] or A[m-2]<=A[m-1]) return false;
        for(int i=0;i<m;i++){
            if(A[i]>mi){
                mi=A[i];
                k=i;
            }
        }
        //if(A[0]==0 and A[1]==k){
           // flag=true;
       // }
        //cout<<mi<<endl;
       // int ma=*max_element(A.begin(),A.end());
        for(int i=0;i<k;i++){
            if(A[i]<A[i+1]){
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        for(int i=k;i<m-1;i++){
            if(A[i]>A[i+1]){
                fla=true;
            }
            else{
                fla=false;
                break;
            }
        }
        if(flag==true && fla==true){
            return true;
        }
        else{
            return false;
        }
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;
        
        while(i+1 < N && A[i] < A[i+1]) i++;
        
        if(i == 0 || i == N-1) return false;
        
        while(i+1 < N && A[i] > A[i+1]) i++;
        
        return i == N-1;
    }
};