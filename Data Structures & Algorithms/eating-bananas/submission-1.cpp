class Solution {
public:
    int solve(vector<int> &piles,int hour)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            double val=ceil((double) piles[i] / (double) hour);
            ans=ans + (int) val;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal=0;
        for(int i=0;i<piles.size();i++) maxVal=max(maxVal,piles[i]);
        int left=1;
        int right=maxVal;
        int ans=0;
        while(left<=right)
        {
            int mid=(left + right ) / 2;
            int val=solve(piles,mid);
            if(val <= h)
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};
