class MedianFinder {
public:
    priority_queue<int, vector<int>> l;
    priority_queue<int, vector<int>, greater<int>> r;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.size() == r.size()){
            if(r.empty() || num <= r.top())
                l.push(num);
            else{
                l.push(r.top());
                r.pop();
                r.push(num);
                // cout<<num<<" "<<l.top()<<endl;
            }
        }
        else{
            if(l.empty() || num >= l.top())
                r.push(num);
            else{
                r.push(l.top());
                l.pop();
                l.push(num);
            }
        }
    }
    
    double findMedian() {
        if((l.size() + r.size())%2 == 0){
            // cout<<1<<endl;;
            return l.top() + (r.top()-l.top())/2.0;
        }
        else{
            // cout<<2<<endl;
            return l.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */