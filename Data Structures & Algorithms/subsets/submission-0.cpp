class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,int curr,vector<int> temp)
    {
        
        ans.push_back(temp);

        for(int i=curr;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(nums,ans,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,0,temp);
        return ans;
    }
};
