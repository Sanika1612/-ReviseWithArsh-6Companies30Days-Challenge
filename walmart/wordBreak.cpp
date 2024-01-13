
//My approch (not optimized)
class Solution {
public:
    set<string>d2;
    bool solve( string s, int i, int j, vector<vector<int>>&dp){
        if(i>s.length()){
             if(j==s.length()) return true;
             else return false;
        }
        if(dp[i][j]!=-1)  return dp[i][j];
       

        bool ans;
        if(d2.find(s.substr(j, i-j))!=d2.end()){
                ans=solve(s, i+1, i,dp);
        }
            return dp[i][j]= (ans or solve(s, i+1, j,dp));
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n=s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<wordDict.size(); i++){
            d2.insert(wordDict[i]);
        }
        return solve( s, 1,0,dp);
        
    }
};
//optimized same approch 
class Solution {
public:
    set<string>d2;
    bool solve( string s, int start, vector<int>&dp){
        if(start==s.length()){
          return true;  
        }
        if(dp[start]!=-1)  return dp[start];
        bool ans=false;
        string temp="";
        for(int i=start; i<s.length(); i++){
            temp+=s[i];
            if(d2.find(temp)!=d2.end()){
                if(solve(s, i+1,dp))
                {ans= true ;
                }
            }
            
        }
        return dp[start]=ans;
        
           
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n=s.length();
        vector<int>dp(n+1, -1);
        for(int i=0; i<wordDict.size(); i++){
            d2.insert(wordDict[i]);
        }
        return solve( s, 0,dp);
        
    }
}; 

//tabulation
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sSz = s.size();
        unordered_set<string> dict;
        for(auto word : wordDict)dict.insert(word);
        vector<int> safeState(sSz+1, 0);


        safeState[0] = 1;
    
        for(int len = 1; len <= sSz; len++){
            for(int left = len-1; left > -1; left--){
                if(safeState[left]){
                    if(dict.find(s.substr(left, len - left)) != dict.end()){
                        safeState[len] = 1;
                        break; 
                    }
                }    
            }
        }
        return safeState[sSz];
    }
};
