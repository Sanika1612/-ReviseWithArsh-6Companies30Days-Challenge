class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;
        if(x>y){
            ans+=y*2+(y+1)*2;
        }
        else if(y>x){
            ans+=x*2+(x+1)*2;
        }
        else{
            ans+=x*2+y*2;
        }
        ans+=z*2;
        return ans;
    }
};
