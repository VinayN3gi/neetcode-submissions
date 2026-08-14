class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int val=1;
        for(int i=0;i<nums.size();i++)
        {
            val=val * nums[i];
            ans=max(ans,val);
            if(val==0) val=1;
        }
        val=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            val=val * nums[i];
            ans=max(ans,val);
            if(val==0) val=1;
        }
        return ans;
    }
};
