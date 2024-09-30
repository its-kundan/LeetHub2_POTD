class CustomStack {
    int size;
    vector<int> arr;
public:
    CustomStack(int maxSize) {
       size = maxSize;
    }
    
    void push(int x) {
        if(arr.size() < size)
            arr.push_back(x);
    }
    
    int pop() {
        if(arr.size() == 0)
            return -1;
        else{
            int res=arr.back();
            arr.pop_back();
            return res;
        }
        
    }
    
    void increment(int k, int val) {
        int x = k;
        if(arr.size() < k)
            x = arr.size();
        for(int i=0; i < x; i++){
            arr[i] += val;
        }
    }
};
