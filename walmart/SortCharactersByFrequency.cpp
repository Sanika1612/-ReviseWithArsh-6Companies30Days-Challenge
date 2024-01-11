class Solution {
public:
   
    string frequencySort(string s) {
        vector<pair<int, char>>v;
        sort(s.begin(),s.end());
        int n=s.length();
        for(int i=0; i<s.length(); i++){
            int c=1;
            while(i+1<n && s[i]==s[i+1])
            {
                    c++; i++;
            }
            v.push_back({c, s[i]});
        }
        sort(v.begin(), v.end());
        int i=0;
        for(int j=v.size()-1; j>=0; j--){
            int p=v[j].first;
            while(p>0){
                s[i]=v[j].second;
                i++;
                p--;
            }
        }
        return s;
        
    }
};
