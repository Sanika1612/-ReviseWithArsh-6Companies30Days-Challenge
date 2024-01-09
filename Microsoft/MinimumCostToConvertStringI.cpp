class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>v(26, vector<long long>(26, 1e18));
     
     
        for(int i=0; i<cost.size(); i++){
            int row=original[i]-'a',col=changed[i]-'a';
            long long cst=cost[i];
            //This step is most important (to take minimum) as there can be more that two values 
            //for same pair of characters
           v[row][col]=min(cst, v[row][col]);
         
          
        }
        for(int i=0; i<26; i++){
            v[i][i]=0;
        }

      for(int k=0; k<26; k++){
          for(int i=0; i<26; i++){
           for(int j=0; j<26; j++){
             
               if(v[i][k]!=1e18 && v[k][j]!=1e18){
               long long nw=v[i][k]+v[k][j];
               if(v[i][j]>nw){
                   v[i][j]=nw;
               }
               }
           }
        }

      }
    //   for(int i=0; i<26; i++){
    //        for(int j=0; j<26; j++){
    //            cout<< v[i][j]<<" ";
    //        }
    //        cout<<endl;
    //     }
      long long ans=0;
      for(int i=0; i<source.size(); i++){
          int row=source[i]-'a',col=target[i]-'a';
       
          if(v[row][col]==1e18) return -1;
          ans=(ans+v[row][col]);
      }
    
      return ans;
       
    }
};
