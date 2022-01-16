class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        /*int n=seats.size();
        vector<int>left(n);
        vector<int>right(n);
        fill(left.begin(),left.end(),n);
        fill(right.begin(),right.end(),n);*/
        /*for(int i=0;i<n;i++){
            cout<<left[i];
        }
        for(int i=0;i<n;i++){
            cout<<right[i];
        }*/
        /*for(int i=0;i<n;++i){
            if(seats[i]==1) left[i]=0;
            else if(i>0) left[i]=left[i-1]+1;
        }
        for(int i=n-1;i>=0;--i){
            if(seats[i]==1) right[i]=0;
            else if(i<n-1) right[i]=right[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(seats[i]==0){
                ans=max(ans,min(left[i],right[i]));
            }
        }
        return ans;*/
        /*int n=seats.size();
        int prev=-1,future=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                prev=i;
                //cout<<prev;
            }else{
                while(future<n && (seats[future]==0 || future<i))
                    future++; //cout<<future;
                
                int left=prev==-1 ? n:i-prev;//cout<<i-prev; 
                int right=future==n ? n:future-i;cout<<right;
                ans=max(ans,min(left,right));
            }
        }
        return ans;*/
        int n=seats.size();
        int k=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                k=0;
            }else{
                k++;
                ans=max(ans,(k+1)/2);
                //cout<<ans;
            }
        }
        for(int i=0;i<n;i++) if(seats[i]==1){
            //cout<<i;
            ans=max(ans,i);
            //cout<<ans;
            break;
        }
        for(int i=n-1;i>=0;--i) if(seats[i]==1){
            //cout<<n-1-i;
            ans=max(ans,n-1-i);
            break;
        }
        return ans;
    }
};