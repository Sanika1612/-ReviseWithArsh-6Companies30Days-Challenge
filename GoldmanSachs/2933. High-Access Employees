class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        vector<string>ans;

        for(int i=0; i<access_times.size(); i++){
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));

        }
        for(auto &itr: mp){
            sort(itr.second.begin(), itr.second.end());
            
        }
        for(auto &itr: mp){
            for(int j=0; j<itr.second.size(); j++){
                if(j+2<itr.second.size() && itr.second[j+2]-itr.second[j]<100){
                    ans.push_back(itr.first);
                    break;
                }

            }
        }
        return ans;
        

    }
};
