class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> temp(amount + 1 , INT_MAX);
        temp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int x:coins)
            {
                if(i < x) continue;
                else
                {
                    if(temp[i-x]!=INT_MAX)
                    {
                        int val=1 + temp[i-x];
                        temp[i]=min(temp[i],val);
                    }
                }
            }
        }
        if(temp[amount]==INT_MAX) return -1;
        return temp[amount];
    }
};
