class MaxCompare
{
    public:
        bool operator()(int a , int b)
        {
            return a < b;
        }
};
class MinCompare
{
    public:
        bool operator()(int a,int b)
        {
            return a > b;
        }
};
class MedianFinder {
public:
    priority_queue<int,vector<int>,MaxCompare> maxHeap;
    priority_queue<int,vector<int>,MinCompare> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();

            maxHeap.push(b);
            minHeap.push(a);
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 == 0)
        {
            double val=(double) maxHeap.top() + (double) minHeap.top();
            return val / 2.0;
        }
        else return maxHeap.top();
    }
};
