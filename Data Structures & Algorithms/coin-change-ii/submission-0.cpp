class Solution {
   public:
    int solve(int amount, vector<int>& coins,int curr, int sum,vector<vector<int>> &seen) {
        //amount , curr
        if (amount == sum) return 1;
        if (sum > amount) return 0;
        if(seen[sum][curr]!=-1) return seen[sum][curr];
        int ans=0;
        for(int i=curr;i<coins.size();i++)
        {
            ans=ans + solve(amount,coins,i,sum + coins[i],seen);
        } 
        seen[sum][curr]=ans;
        return ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> seen(amount + 1 , vector<int>(coins.size(),-1));
        return solve(amount,coins,0,0,seen);
    }
};
