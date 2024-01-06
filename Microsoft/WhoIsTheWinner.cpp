// We can also solve this question using circular linked list or queue 

// Using Circular Linked List:
// Create circular linked list of size n and stimulate the process

// Using queue
// Pop front element of queue and push from back. Do this for k time. and pop front element(kth element) . 
// Do this till queue size becomes 1




//Solution 1:
//Most optimized iterative approch with 
// space complexity: O(1) 
// time complexity : O(n)
class Solution {
public:

    int findTheWinner(int n, int k) {
        int ans=0;
    
        for(int i=0; i<n; i++){
         ans=(ans+k)%(i+1);
        }
        return ans+1;
    }
};
//Solution 2:
//Recursive approch with 
// space complexity: O(1) 
// time complexity : O(n)
class Solution {
public:
   int solve(int n, int k){
       if(n==1) return 0;
       
       return (solve((n-1),k)+k )%n;
   }
    int findTheWinner(int n, int k) {
        return solve(n,k)+1;
    }
};

//Solution 2: Worst solution
class Solution {
public:
    int findTheWinner(int n, int k) {

        //Crazy approach beats only 5% :). But its my solution.
        int i=0,start=0,c=1;
        vector<int>v(n,0);
        bool f=true;
        if(k==1) return n;
    
        while((i!=start || c!=1) || f){
            i++;
            
            if(i==n){
                i=i%(n);
            }
            if(v[i]!=-1)
            c++;
            else continue;
            if(c==k){
                v[i]=-1;
                start=i;
                c=0;
            }

            f=false;
        }

        for(int i=0; i<n; i++){
            if(v[i]!=-1) return i+1;
        }
        return -1;
    }
};
