vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> arr = A;
    int repeated = -1;
    int missing = -1; 
    int n1 = arr.size();
    for(int i=0;i<n1;i++){
        if(arr[abs(arr[i])-1] > 0){
            arr[abs(arr[i])-1] = -1*arr[abs(arr[i])-1];
        }else{
            repeated = abs(arr[i]);
        }
    }
    for(int i=0;i<n1;i++){
        if(arr[i] > 0){
            missing = i+1;
        }
    }
    vector<int> temp;
    temp.push_back(repeated);
    temp.push_back(missing);
    return temp;
}