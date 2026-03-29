class DataStream {
public:
    vector<int> stream;
    int value;
    int k;
    int last;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        stream.push_back(num);
        int n = stream.size();
        if(num != value) last = n;

        if(stream.size() < k) return false;
        if(last > n-k) return false;
        return true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */