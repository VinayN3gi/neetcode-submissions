class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {   
                if(nums[i] > nums[j]) 
                {
                    temp[i]=max(temp[i],1 + temp[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<temp.size();i++) ans=max(ans,temp[i]);
        return ans;
    }
};
