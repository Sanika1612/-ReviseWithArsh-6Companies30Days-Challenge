class DataStream {
public:
    vector<int>stream;
    int val, kval, inc;
    DataStream(int value, int k) {
       val=value;
       kval=k;
       inc=0;
    }
    
    bool consec(int num) {

        stream.push_back(num);
        if(num==val){
            inc++;
        }
        else{
            inc=0;
        }
        if(inc>=kval){
            return true;
        }
        return false;

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
