class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> temp(cost.size() + 1,0);
        temp[0]=0;
        temp[1]=0;
        for(int i=2;i<=cost.size();i++)
        {   
            temp[i]=min(temp[i-1] + cost[i-1],temp[i-2] + cost[i-2]);
        }
        return temp[cost.size()];
    }
};
