//Solution 1 

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

//Solution 2 (optimized)
class Solution {
public:
        int countDistinct(vector<int>& nums, int k, int p) {

        //Optimization using hashing(rolling hash) 
        //TC: O(n^2)

        unordered_map<int, unordered_set<int>> hashMap; //len, {hash}

        int res = 0;

        for (int i=0; i<nums.size(); i++){
            long long hash = 0, cntP = 0, mod = 1e9+7, pow = 200;
            for(int j=i; j < nums.size(); j++){
                if (nums[j] % p == 0) 
                cntP++;
                if (cntP <= k) {
                hash = (hash * pow + nums[j]) % mod;
                if (hashMap[j-i+1].insert(hash).second) res++;
                }
            }
        }
        return res;
    }
};
