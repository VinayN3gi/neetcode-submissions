class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> temp(n+1,0);
        temp[1]=1;temp[2]=2;
        for(int i=3;i<=n;i++)
        {
            temp[i]=temp[i-1] + temp[i-2];
        }
        return temp[n];
    }
};
