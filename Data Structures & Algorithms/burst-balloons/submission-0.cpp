class Solution {
public:
    int solve(int left,int right,vector<int> &arr,vector<vector<int>> &seen)
    {
        if(left > right) return 0;
        int ans=0;
        if(seen[left][right]!=-1) return seen[left][right];
        for(int k=left + 1 ; k<right ; k++)
        {
            int val=arr[left] * arr[k]  * arr[right];
            val=val + solve(left,k,arr,seen);
            val=val + solve(k,right,arr,seen);
            ans=max(ans,val);
        }
        seen[left][right]=ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2 , 1);
        vector<vector<int>> seen(arr.size() + 2 , vector<int>(arr.size() + 2 , -1));
        for(int i=0;i<nums.size();i++)
        {
            arr[i+1]=nums[i];
        }
        return solve(0,nums.size() + 1 , arr,seen);
    }
};
