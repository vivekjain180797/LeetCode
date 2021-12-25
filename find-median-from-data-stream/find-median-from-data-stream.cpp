class MedianFinder {
    
    //Max heap [2, 3,4 ]
    priority_queue <int> small;
    //Min heap [5,6,7]
    priority_queue <int , vector<int>, greater<int>> large;
    // we can find median using top element of both queue 
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       small.push(num);
       large.push(small.top());
       small.pop();
       if(small.size()<large.size()){
        small.push(large.top());
        large.pop();   
       }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */