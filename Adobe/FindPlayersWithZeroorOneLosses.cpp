class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>all;
        unordered_map<int, int>losers;
        vector<int>a,b;
        for(int i=0; i<matches.size(); i++){
            all.insert(matches[i][0]);
            all.insert(matches[i][1]);
            losers[matches[i][1]]++;
        }
        for(auto i: all){
            if(losers.find(i)==losers.end()){
               a.push_back(i);
            }
            else if(losers[i]==1){
                b.push_back(i);
            }
        }
        vector<vector<int>>ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        


    }
};
