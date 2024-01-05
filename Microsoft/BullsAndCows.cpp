class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>fre(10 ,0);
        int b=0, c=0;
        for(int i=0; i<secret.length(); i++){
             fre[secret[i]-'0']++;
            if(secret[i]==guess[i]){
                b++;
            }
            
        }
        for(int i=0; i<secret.size(); i++){
            if( fre[guess[i]-'0']>0 ){
                c++;
                fre[guess[i]-'0']--;
            }
        }
       c-=b;
        string ans=to_string(b)+ "A";
        ans+=  to_string(c)+ "B";
        return ans;
    }
};
