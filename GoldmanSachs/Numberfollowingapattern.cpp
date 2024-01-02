//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int itr=1,n=S.length();
        string ans;
        
        
        for(int i=0; i<S.length(); i++){
            
            //if char is I
            if(S[i]=='I')
            {
                ans.push_back(itr+'0');
                itr++;
            }
            else{
                //store current value of itr in temp
                int temp=itr;
                while(S[i]=='D' && i<n){
                    itr++;
                    i++;
                    
                }
                  
                
                int temp2=itr;
                while(itr>temp){
                    ans.push_back(itr+'0');
                    itr--;
                }
                
                    ans.push_back(itr+'0');
                
                itr=temp2+1;
                
            }
        }
        if(S[n-1]=='I'){
            ans.push_back(itr+'0');
        }
      ]
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
