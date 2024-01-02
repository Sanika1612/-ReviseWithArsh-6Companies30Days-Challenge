class Solution {
public:
   set<pair<int, int>>s;
   int row, column;
    Solution(int m, int n) {
        row=m;
        column=n;

    }
    
    vector<int> flip() {
        int r=rand()%row;
        int c=rand()%column;
     if(s.find({r,c})==s.end()){
         s.insert({r,c});
         return {r,c};
     }
     else return flip();
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
