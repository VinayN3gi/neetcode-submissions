class Solution {
public:
    double solve(double x , int n)
    {
        if(x==0) return 0;
        if(n==0) return 1;
        double ans=solve(x,n/2);
        ans=ans * ans;
        if(n % 2 == 0) return ans;
        else return x * ans;
    }
    double myPow(double x, int n) {
        double val=solve(x,abs(n));
        if(n < 0) return 1/val;
        return val;
    }
};
