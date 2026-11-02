class Solution {
public:
    void solve(vector<vector<int>> &ans,
    vector<int> &temp,vector<int> &nums,int target,int sum,int idx)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return ;
        }
        if(idx>=nums.size() || sum > target) return ;
        for(int i=idx;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(ans,temp,nums,target, sum + nums[i],i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,nums,target,0,0);
        return ans;
    }
};
