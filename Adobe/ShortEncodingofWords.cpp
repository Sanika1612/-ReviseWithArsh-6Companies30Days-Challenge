// TC: O(n^3)
// SC:O(1)

class Solution {
public:
 static bool compare(string &s1,string &s2)
{
    return s1.size() > s2.size();
}

    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        sort(words.begin(), words.end(),compare);
        ans+=words[0].length()+1;
        
        for(int i=1; i<words.size(); i++){
            bool f=false;
            int m=words[i].length();
            for(int j=0; j<i; j++ ){
                int n=words[j].length();
                  
                  if(words[j][n-m]==words[i][0] && words[j].substr(n-m, m)==words[i]){
                       f=true;
                      break;
                  }

            }
            if(!f){
                    ans+=m+1;
            }
        }
        return ans;
    }
};
