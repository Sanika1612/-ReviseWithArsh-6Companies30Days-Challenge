class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size();
        vector<vector<int>>v(n, vector<int>(m, -1));
        // vector<int>visited(m*n, 0);
        vector<int>dx={1, -1, 0, 0};
        vector<int>dy={0, 0, 1, -1};
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    v[i][j]=0;
                    q.push({i, j});
                   

                }
            }
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int mn=v[x][y];
        
            for(int k=0; k<4; k++){
                if(x+dx[k]<n && y+dy[k]<m && x+dx[k]>=0 && y+dy[k]>=0){
                 
                    if(v[x+dx[k]][y+dy[k]]==-1)
                   {      v[x+dx[k]][y+dy[k]]=mn+1;
                        q.push({x+dx[k],y+dy[k]} );
                   }
                }
                
            }
            

        }
        return v;
    }
};
