class MedianFinder {
    int size;
    //max heap
    priority_queue<int> pq;
    //min heap
    priority_queue<int,vector<int>,greater<int>> p;
public:
    MedianFinder() {
        size=0;    
    }

    void balance(){
        int n=pq.size();
        int m=p.size();
        if(n==m)return;
        if(n==m+1)return;
        if(n>m+1){
            int temp=pq.top();
            pq.pop();
            p.push(temp);
        }
        else if(m>n){
            int temp=p.top();
            p.pop();
            pq.push(temp);
        }
    }
    
    void addNum(int num) {
        if(pq.empty()||num<=pq.top()){
            pq.push(num);
        }
        else{
            p.push(num);
        }
        balance();
        size++;   
    }
    
    double findMedian() {
        double ans;
        if(size%2==1){
            ans=pq.top();
        } 
        else{
            ans= (double)(pq.top() + p.top())/2.0;
        }  
        return ans; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */