class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {       //space complexity : O(n)
        //time complexity: O(queries.size()*nlogn);
         int n=nums[0].size();
        vector<int>ans;
    //iterate all queries one by one
    for(int i=0; i<queries.size(); i++){
        int index=queries[i][0]; 
        int t=queries[i][1];
        //Use vector to store substring and its index
        vector<pair<string, int>>v; 
     
                
        for(int j=0; j<nums.size(); j++){
                v.push_back({(nums[j].substr(n-t)), j});
         }
        //sort the vector
        sort(v.begin(), v.end());
        ans.push_back(v[index-1].second);   
          
        v.clear();
    }
    return ans;
    }
};
