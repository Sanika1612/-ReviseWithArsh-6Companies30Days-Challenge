//Dp memoization
class Solution {
public:vector<int>ans;
     
    void solve(vector<int>&nums, int index, vector<int>&v,vector<int>&dp){
        if(index>=nums.size()){
          if(ans.size()<v.size()){
              ans=v;
          }
          return;
        }
       
        //We can't directly use temp.size() without typecasting because it will return an unsigned int and hence if() will not work.
      
        if((int)v.size()>dp[index] && (v.size()==0 || v.back()%nums[index]==0 || nums[index] % v.back()==0)){
                  dp[index]=v.size();
                 v.push_back(nums[index]);
                  solve(nums, index+1, v,dp);
                  v.pop_back();
        }
        solve(nums, index+1, v,dp);
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       vector<int>v;
       //Given subset not subsequence
       //And every two pairs should satisfy the condition so we sort
       sort(nums.begin(), nums.end());
       vector<int>dp(nums.size()+1, -1);
       solve(nums, 0, v,dp);
       return ans;
    }
};
