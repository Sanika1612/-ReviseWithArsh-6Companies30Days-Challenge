
//My apporach 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        vector<string>ans;
        
        for(auto i: words){
            mp[i]++;
        }
        vector<pair<int, string>>v;
        for(auto i: mp){
                v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        
        for(auto i: v) cout<<i.first<<" "<<i.second<<endl;
       for(int i=v.size()-1; k>0 && i>=0; i--){
           vector<string>temp;
           while(i-1>=0 && v[i].first==v[i-1].first){
              temp.push_back(v[i].second);
              i--;
           }
           if(temp.size()!=0)
           temp.push_back(v[i].second);
           sort(temp.begin(), temp.end());
           if(temp.size()!=0){
              for(int p=0; p<temp.size() && k>0 ; p++){
                ans.push_back(temp[p]);
                k--;
               }
           }
           else{
               ans.push_back(v[i].second);
              k--;
           }
           
           
           
       }
 
        return ans;
    }
};

//optimised
class Solution {
public:
    static bool cmp(pair<string, int>a, pair<string, int>b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        vector<string>ans;
        
        for(auto i: words){
            mp[i]++;
        }
        vector<pair<string, int>>v;
        for(auto i: mp){
                v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), cmp);
          
         for(auto i: v){
             if(k==0) break;
             ans.push_back(i.first);
             k--;
         }

        return ans;
    }
};
