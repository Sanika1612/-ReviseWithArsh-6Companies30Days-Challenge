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
