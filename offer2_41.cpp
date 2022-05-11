class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > maxheap;    //大于中位数的数
    priority_queue<int, vector<int>, greater<int> > minheap; //小于中位数的数

    MedianFinder() {}
    
    void addNum(int num) {
        if(maxheap.size() == minheap.size()) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        return maxheap.size() == minheap.size() ? ((maxheap.top() + minheap.top()) * 0.5) : minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
