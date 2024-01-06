class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        if(s.length()<10) return ans;
        unordered_map<string, int>mp;
      
        for(int i=0; i<s.length()-9; i++){
            mp[s.substr(i, 10)]++;
        }
        for(auto i: mp){
          
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};


// Optimized: 
class Solution {
public: 
//Rabin Carp Rolling Hash
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n=s.length();
        unordered_map<long long,int> m;
        if(n<10) return ans;
         int inp[n];
         for(int i=0;i<n;i++){
            if(s[i]=='A') inp[i]=1;
            else if(s[i]=='C') inp[i]=2;
            else if(s[i]=='G') inp[i]=3;
            else inp[i]=4;
        }
        long long hash=0;
        for(int i=0; i<10; i++){
            hash=hash*4+(inp[i]);
        }
        
        m[hash]++;
    
        for(int i=10; i<s.length(); i++){
            hash=hash*4-inp[i-10]*pow(4,10)+inp[i];
            m[hash]++;
            if(m[hash]==2){
             ans.push_back(s.substr(i-9, 10));
            }
            
            
        }
        return ans;
    }
};



