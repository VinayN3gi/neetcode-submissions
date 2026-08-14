class Solution {
public:
    int solve(vector<int> &prices,int curr,int canBuy,vector<vector<int>> &seen)
    {
        //curr , canBuy
        if(curr >=prices.size()) return 0;
        if(seen[curr][canBuy]!=-1) return seen[curr][canBuy];
        int ans=0;
        if(canBuy)
        {
            int val1=-prices[curr] + solve(prices,curr+1,0,seen);
            ans=max(ans,val1);
            int val2=solve(prices,curr+1,1,seen);
            ans=max(ans,val2);
            seen[curr][canBuy]=ans;
            return ans;
        }
        else
        {
            int val1=prices[curr] + solve(prices,curr+2,1,seen);
            ans=max(ans,val1);
            int val2=solve(prices,curr+1,0,seen);
            ans=max(ans,val2);
            seen[curr][canBuy]=ans;
            return ans;
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> seen(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,seen);
    }
};
