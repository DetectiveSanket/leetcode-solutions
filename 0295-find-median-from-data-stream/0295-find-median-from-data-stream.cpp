#include <queue>
#include <vector>

class MedianFinder {
private:
    // Stores the smaller half (top is the max of the smaller half)
    std::priority_queue<int> maxHeap;
    
    // Stores the larger half (top is the min of the larger half)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);
        
        // Step 2: Ensure order invariant by pushing top of maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Step 3: Ensure size invariant (maxHeap size is either equal or 1 greater)
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */