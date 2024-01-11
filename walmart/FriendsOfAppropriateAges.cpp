// x>y/2+7 &&x<=y
// ->or we can say (y/2+7<x<=y)

// ->now to find val >y/2+7 we can apply binary search

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
       sort(ages.begin(),ages.end());
        int count =0;
        for(int i=0;i<ages.size();i++)
        {
             int val=ages[i]/2+7;
            if(ages[i]<=val) //invalid condition
                continue;
            
            int ind1=upper_bound(ages.begin(),ages.end(),val)-ages.begin();
            int ind2=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
            
            ind2--;         //because upper bound will give val greater than ages[i] soo we need to decrement ind2 to get 
            if(ind2>=ind1)    // val<=ages[i]
                count+=ind2-ind1;
            
         }
        
        return count;
    }
};


//My solution using binary search
class Solution {
public:
    int binarySearch(vector<int>& ages, int keyIndex, int end){
        int start=keyIndex+1, key=ages[keyIndex],value=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if((float)key<=(float)(0.5*ages[mid]+7)){
                end=mid-1;
            }
            else{
                value=mid;
                start=mid+1;
                
            }
            
        }
        int extra=0;
        for(int i=keyIndex+1; i<=value; i++){
            if(ages[keyIndex]==ages[i]){
                extra++;
            }
            else{
                break;
            }
        }

        if(value!=-1)
        return value-keyIndex+extra;
        return 0;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n=ages.size()-1,ans=0;
        for(int i=0; i<ages.size()-1; i++){
            int num=binarySearch(ages, i, n );
            ans+=num;
        }
        return ans;
    }
};

//Using hashing 
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int>mp;
        for(int i=0; i<ages.size(); i++){
            mp[ages[i]]++;
        }
        int ans=0;
        for(auto i: mp){
            for(auto j: mp){
                if(j.first>i.first*0.5+7 && j.first<=i.first){
                    ans+=i.second*(j.second-((i.first==j.first)?1:0));
                }
            }
        }
        return ans;
    }
};
