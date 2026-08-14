class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &nums,vector<int> temp,int sum,int target,int curr)
    {
        if(target==sum)
        {
            ans.push_back(temp);
            return ;
        }
        if(target < sum || curr > nums.size()) return ;
        for(int i=curr;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(ans,nums,temp,sum + nums[i],target,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,nums,temp,0,target,0);
        return ans;
    }
};
