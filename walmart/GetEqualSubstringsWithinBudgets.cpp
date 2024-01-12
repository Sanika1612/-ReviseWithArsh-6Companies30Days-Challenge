class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j=0;
        int ans=0;
        int mx=0;
        for(int i=0; i<s.length(); i++){
            ans+=abs(s[i]-t[i]);
            while(ans>maxCost){
                ans-=abs(s[j]-t[j]);
                j++;
                
            }
            mx=max(mx, i-j+1);
        }
        return mx;
    }
};
