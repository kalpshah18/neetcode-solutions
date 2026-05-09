class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return myPow(1 / x, -1 * n);
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n & 1){
            return myPow(x * x, n / 2) * x;
        } else {
            return myPow(x * x, n / 2);
        }
    }
};
