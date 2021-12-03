class Solution {
public:
    double pw(double x,int n){
        //base case
        if(n==0) return 1;
        if(n==1) return x;
        //recursive case
        double temp = pw(x,n/2);
        return n%2==0?temp*temp:temp*temp*x;
    }
    double myPow(double x, int n) {
        return n>=0?pw(x,n):1/pw(x,abs(n));
    }
};