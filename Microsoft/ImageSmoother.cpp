class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //TC: O(m*n*8)= O(m*n);
        //SC: O(m*n*16)=O(m*n);
        //space complexity can be reduced further (refer tutorial of this question)
        int m=img.size(), n=img[0].size();
        vector<int>dx={0, 0, 1, -1, -1, 1, -1, 1};
        vector<int>dy={1, -1, 0, 0, -1, 1, 1, -1};
        vector<vector<int>>ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int sum=img[i][j];
                int c=1;
              for(int k=0; k<8; k++){
                  if(i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n){
                       c++;
                       sum+=img[i+dx[k]][j+dy[k]];
                  }
              }
              ans[i][j]=sum/c;
            }
        }
        return ans;
    }
};
