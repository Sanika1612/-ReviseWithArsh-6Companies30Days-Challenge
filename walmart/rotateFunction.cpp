class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        //Calculate f(k+1)-f(k) (for reference take f(0) & f(1) also f(1) & f(0))
        //will get f(k+1) = f(k) - (n-1)arr[n-i]+ sum -arr[n-i]
        //Simplifying we will get f(k+1)= f(k) -n*arr[n-i]+sum
        int f0=0,n=nums.size(),sum=0;
        for(int i=0; i<n; i++){
            f0+=nums[i]*i;
        
            sum+=nums[i];
        }
        int fpre=f0, fnext,mx=f0;
     
        for(int i=n-1; i>=0; i--){
            
            fnext=fpre-(n)*nums[i]+sum;
            mx=max(mx, fnext);
            fpre=fnext;
        }
        return mx;
    }
};
