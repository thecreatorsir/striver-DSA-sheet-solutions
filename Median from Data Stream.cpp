class MedianFinder {
public:
    /** initialize your data structure here. */
     priority_queue<int> mx;
     priority_queue<int,vector<int>,greater<int>> mn;
     double median = 0;
    void addNum(int num) {
        if(mx.empty()){
            mx.push(num);
            median = findMedian();
        }else{
            if(num>=median){
                //then it will go into min heap
                if(mn.size()-mx.size()==1){
                    //remove from mn and insert into mx
                    mx.push(mn.top());
                    mn.pop();
                }
                mn.push(num);
               
                median = findMedian();
                
            }else{
                //go into max heap
                if(mx.size()-mn.size()==1){
                    //remove from mx and insert into mn
                    mn.push(mx.top());
                    mx.pop();
                }
                mx.push(num);
                
                median = findMedian();
            }
        }
    }
    
    double findMedian() {
        if(mx.size() > mn.size()){
            return (double)mx.top();
        }else if(mx.size() < mn.size()){
            return (double)mn.top();
        }else{
            return double(mx.top()+mn.top())/2;
        }
    }
};
