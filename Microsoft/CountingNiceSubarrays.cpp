class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int j=0,firstj=-1,odds=0,pre=0,post=0,ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1){
                odds++;
                if(firstj==-1){
                 
                    firstj=i;
                    j=i;
                }
            }
            if(odds==k+1){
                post+=1;
              pre+=1;
                ans+=(post*pre);
                // cout<<pre<<' '<<post<<" "<<i<<" "<<j<<endl;
                post=0; pre=0;
                j+=1;
                
                while(j<nums.size() && nums[j]%2!=1){
                    j++;
                    pre++;
                }
                odds-=1;
            }
           
          else if(odds==0 ){
                if(nums[i]%2==0) {
                     pre++;
                }
            }
          else if(odds==k && nums[i]%2==0) {
            post++;
            }

        }
        // cout<<pre<<" "<<post<<endl;
        if(pre==nums.size() || odds<k) return 0;

                post+=1;
                pre+=1;
                ans+=(post*pre);
                
                
                
             
               
            
          

        return ans;

    }
};
