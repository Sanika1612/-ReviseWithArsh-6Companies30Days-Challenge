class Solution {
public:
   
    vector<vector<int>>rect;
    Solution(vector<vector<int>>& rects) {
   
        rect=rects;
    }
    
    vector<int> pick() {
        // "randomly and uniformily picks an integer point in the space covered by the rectangles"
        //probability: 1 / (n + m)

        //if we first select rectangle randomly and then point then probability changes to 
        // probability_of_getting_p1i = 1 / (2 * n)
        // probability_of_getting_p2j = 1 / (2 * m)

        // Where n is the size of S1, and m is size of S2

        int totalarea=0;
        map<int, vector<int>>mp;
        for(auto i: rect){
            int x1=i[1], x2=i[3], y1=i[0], y2=i[2];
         // I add the +1 here because in some inputs they contain lines also like 
	     // [ 1,2,1,3 ] ( rectangle with height 0 or width 0 but this also contains 2 points )
	     // to also add these points I add +1.
            int area= (x2-x1+1)*(y2-y1+1);
            totalarea+=area;
            mp[totalarea]=i;
        }
        //Choose random number
        int area=rand()%totalarea;
        //choose vector of that area
        auto ptr=mp.upper_bound(area);

        vector<int>v=ptr->second;

        int x=v[0]+rand()%(v[2]-v[0]+1);
        int y=v[1]+rand()%(v[3]-v[1]+1);
        return {x, y};

      
     
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
