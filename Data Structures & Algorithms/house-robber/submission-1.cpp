class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> temp(nums.size() + 1,0);
        temp[0]=0;
        temp[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            temp[i]=max(temp[i-1], nums[i-1] + temp[i-2]);
        }
        return temp[nums.size()];
    }
};
