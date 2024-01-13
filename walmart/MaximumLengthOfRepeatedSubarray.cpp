//BruteForce TC: O(n^3)

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int ans=-1;
        for(int i=0; i<n1; i++){
            
            for(int j=0; j<n2; j++){
                int c=0;
                int temp1=i, temp2=j;
                  if(nums1[i]==nums2[j]){
                       while(i<n1 && j<n2 && nums1[i]==nums2[j]){
                           c++;
                           i++;
                           j++;
                       }
                  }
                //   cout<< i <<" "<<j<<" "<< c<<" "<<endl;
                  i= temp1; j=temp2;
                  ans=max(ans, c);
                  if(n2-j<ans) break;
            }
            if(n1-i<ans) break;
        }
  
        return ans;
    }
};


//using dp
// TC O(n^2)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        int ans=0;
        for(int i=1; i<nums1.size()+1; i++){
            for(int j=1; j<nums2.size()+1; j++){
                 if(nums1[i-1]==nums2[j-1]){
                     dp[i][j]=dp[i-1][j-1]+1;
                     ans=max(dp[i][j], ans);
                 }
            }
        }
        return ans;

    }
};

