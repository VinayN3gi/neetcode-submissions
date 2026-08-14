class Solution {
public:
    bool solve(vector<int> &nums,vector<vector<int>> &memo,int i,int sum,int target)
    {
        if(target==sum) return true;
        if(i >=nums.size()) return false;
        if(memo[i][sum]!=-1) return memo[i][sum];
        bool ans=false;
        ans=ans | solve(nums,memo,i+1,sum + nums[i],target);
        ans=ans | solve(nums,memo,i+1,sum,target);
        memo[i][sum]=ans;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum=sum + nums[i];
        if(sum % 2 !=0) return false;
        vector<vector<int>> memo(nums.size(),vector<int>(sum + 1 , -1));
        return solve(nums,memo,0,0,sum/2);
    }
};
