class Solution {
public:
    int findTheWinner(int n, int k) {

        //Crazy approach beats only 5% :). But its my solution.
        int i=0,start=0,c=1;
        vector<int>v(n,0);
        bool f=true;
        if(k==1) return n;
    
        while((i!=start || c!=1) || f){
            i++;
            
            if(i==n){
                i=i%(n);
            }
            if(v[i]!=-1)
            c++;
            else continue;
            if(c==k){
                v[i]=-1;
                start=i;
                c=0;
            }

            f=false;
        }

        for(int i=0; i<n; i++){
            if(v[i]!=-1) return i+1;
        }
        return -1;
    }
};
