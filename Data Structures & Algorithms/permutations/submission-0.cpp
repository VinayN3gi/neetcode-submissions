class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> temp,
    vector<int> &nums,vector<int> seen)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(seen[i]) continue;
            temp.push_back(nums[i]);
            seen[i]=1;
            solve(ans,temp,nums,seen);
            temp.pop_back();
            seen[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> seen(nums.size(),0);
        solve(ans,temp,nums,seen);
        return  ans;
    }
};
