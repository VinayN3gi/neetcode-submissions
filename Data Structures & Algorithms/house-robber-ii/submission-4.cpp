class Solution {
public:
    int exLast(vector<int> &nums)
    {
        vector<int> dp(nums.size(),0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1] , dp[i-2] + nums[i - 1]);
        }
        return dp[nums.size() - 1];
    }
    int exFirst(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=nums.size();i++)
        {
            dp[i]=max(dp[i-1], dp[i-2] + nums[i-1]) ;
        }
        return dp[nums.size()];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        return max(exFirst(nums),exLast(nums));
    }
};
