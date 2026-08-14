class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &nums,
    vector<int> &temp,vector<int> seen,int curr)
    {
        ans.push_back(temp);
        for(int i=curr;i<nums.size();i++)
        {
            if(i > 0 && (nums[i]==nums[i-1] && !seen[i-1])) continue;
            seen[i]=1;
            temp.push_back(nums[i]);
            solve(ans,nums,temp,seen,i+1);
            seen[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> seen(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,nums,temp,seen,0);
        return ans;
    }
};
