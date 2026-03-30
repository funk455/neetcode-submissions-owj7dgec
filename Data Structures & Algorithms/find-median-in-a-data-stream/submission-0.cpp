class MedianFinder {
public:
    vector<int> vec;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        vec.push_back(num);
    }
    
    double findMedian() {
        int size = vec.size();
        sort(vec.begin(),vec.end());
        if (!(size % 2)) {
            double mid = (vec[size/2] + vec[size/2-1])/2.0;
            return mid;
        }else {
            return vec[size/2];
        }
    }
};
