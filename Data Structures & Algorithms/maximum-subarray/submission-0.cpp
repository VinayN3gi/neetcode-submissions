class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int val=0;
        for(int i=0;i<nums.size();i++)
        {
            val=val + nums[i];
            ans=max(ans,val);
            if(val < 0) val=0;
        }
        return ans;
    }
};
