class Solution {
public:
    int solve(vector<int> &nums,int curr,int sum,int target,unordered_map<int,unordered_map<int,int>> &mpp)
    {
        if(curr==nums.size())
        {
            if(sum==target) return 1;
            else return 0;
        }
        if(mpp.count(curr) && mpp[curr].count(sum)) return mpp[curr][sum];
        int ans=0;
        ans=ans + solve(nums,curr+1,sum + nums[curr],target,mpp);
        ans=ans + solve(nums,curr+1,sum - nums[curr],target,mpp);
        mpp[curr][sum]=ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> mpp;
        return solve(nums,0,0,target,mpp);
    }
};
