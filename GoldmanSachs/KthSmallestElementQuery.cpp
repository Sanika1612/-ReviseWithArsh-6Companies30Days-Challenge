class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        //Brute force
        //Time complexity: O(n^3) two loops and inserting vector in set
        //Space Complexity: O(n^2);
        set<vector<int>>s;
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            vector<int>v; int c=0;
            for(int j=i; j<n; j++){
                if(nums[j]%p==0) c++;

                 if(c<=k){
                     v.push_back(nums[j]);
                 }
               
                if(!v.empty())
                 {s.insert(v);}
               
            }
            v.clear();
        }
      
            
        int dis= s.size();
        return dis;

    }
};
