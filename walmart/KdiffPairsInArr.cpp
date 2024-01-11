//TC: O(nlogn)
//SC: O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
         int j=0, n=nums.size(),ans=0;
        if(k==0){  
            for(int i=0; i<n-1; i++){
                if(i+1<n && nums[i]==nums[i+1]){
                    ans++;
                    while(i+1<n && nums[i]==nums[i+1]){
                          i++;
                }
                }
                
            }
            return ans;
        }
       
        for(int i=1; i<n; i++){
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
             if(nums[i]-nums[j]>k){
              while(j<i && j<n && nums[i]-nums[j]>k){
                  j++;
              } 
            }
             if(nums[i]-nums[j]==k){
                ans++;
            }

        }
        return ans;
    }
};


// TC: O(n)
// SC: O(n)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};
