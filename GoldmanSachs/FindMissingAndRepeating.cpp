//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
       
       //time complexity :O (nlogn) (sorting arr)
       //space complexith: O(1) 2 sized to store ans 
       
       //we can also solve this question in O(n) space and O(n) time complexity by storing
       //frequency of each element
       
        sort(arr.begin(), arr.end());
        
        vector<int>ans;
        int missing=-1,repeating=-1;
        int i;
      
        for(i=0;i <arr.size(); i++){
            if(arr[i]!=i+1 ){
                if(i-1>=0 && arr[i]==arr[i-1]){
                    repeating=arr[i];
                }
                else missing=i+1;
                break;
            }
           
        }
      
        //If we get missing element first
        if(repeating==-1){
            for(; i<arr.size(); i++){
                if(arr[i]==arr[i+1]) 
                {
                    repeating=arr[i];
                    break;
                }
              
            }
        }
        //if we get repeating element first
        else{
            for(int j=i+1; j<n; j++){
                if(arr[j]!=j) 
                {
                    missing=j;
                    break;
                }
             
            }
        }
        //at last if we don't get missing element
        if(missing==-1) missing =n;
        

       
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
        
        
    }
};
 


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
