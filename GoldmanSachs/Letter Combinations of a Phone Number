class Solution {
public:
     vector<string>ans;
    void solve(vector<string>strs, int strno, string s){
        if(strno>=strs.size()){
            if(s.length()==strs.size()){
                ans.push_back(s);
            }
            return;
        }
        
      for(int i=0; i<strs[strno].size(); i++){
       s+=strs[strno][i];
        solve(strs, strno+1, s);
        s.pop_back();
      }
        

        //next strno + next ind
        //next strno +same ind
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>strs;
        
        for(int i=0; i<digits.size(); i++){
          strs.push_back(mp[digits[i]]);
        }
        string s;
        solve(strs, 0, s);
        return ans;


    }
};
