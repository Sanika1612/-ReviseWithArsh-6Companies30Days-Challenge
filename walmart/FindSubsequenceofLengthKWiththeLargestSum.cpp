//Sorting 
class Solution {
public:
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return  a.second>b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      vector<pair<int, int>>v;
      int n=nums.size();
      for(int i=0; i<nums.size(); i++){
          v.push_back({i, nums[i]});
      }
      sort(v.begin(), v.end(), cmp);
      //sort last k elements based on index
      sort(v.begin(), v.begin()+k);
   
      vector<int>ans;
      for(int i=0; i<k; i++){
          ans.push_back(v[i].second);
      }
      return ans;
    }
};

//Priority queue
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<nums.size(); i++){
            if(pq.size()<k){
                pq.push({nums[i],i});
            }
            else{
                if(pq.size()==k && nums[i]>pq.top().first){
                       pq.pop();
                       pq.push({nums[i], i});
                }
            }
        }
        vector<pair<int, int>>v;
        while(!pq.empty()){
             v.push_back({pq.top().second, pq.top().first});
             pq.pop();
        }
        sort(v.begin(), v.end());
        vector<int>ans;
        for(auto i: v){
            ans.push_back(i.second);
        }
        return ans;


    }
};
