class MedianFinder {
    //maxheap
    priority_queue<int> left;
    //minheap
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        left.push(num);
        //check bigger smaller data
        if(!left.empty() && !right.empty() && left.top()>right.top()){
            right.push(left.top());
            left.pop();
        }
        //check size of data
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())return (left.top()+right.top())/2.0;   
        return left.top();    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */