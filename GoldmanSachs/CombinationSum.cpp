class Solution {
public:
     vector<vector<int>>ans;
     void solve(int k, int n, int index,vector<int>&ds){
         if(k==0) {
             if(n==0){
                 ans.push_back(ds);
                 return;
             }
             return;
         }
         if(k<0 ||n <0) return;
         for(int i=index; i<=9; i++){
             if(n-i>=0){
                  ds.push_back(i);
                  solve(k-1, n-i, i+1, ds);
                  ds.pop_back();
             }
         }
     }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        solve(k, n, 1, ds );
        return ans;
    }
};
