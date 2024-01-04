class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        //Brute force
        //Time complexity: O(n^3)
        //Space Complexity: O(n^2);
        set<vector<int>>s;
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int c=0;
                for(int x=i; x<=j; x++){
                    if(nums[x]%p==0){
                        c++;
                    }
                }
                vector<int>v;
                if(c<=k){
                   for(int x=i; x<=j; x++){
                      v.push_back(nums[x]);
                    }
                } 
                if(!v.empty())
                 {s.insert(v);}
                v.clear();
            }
        }
            
        int dis= s.size();
        return dis;

    }
};
