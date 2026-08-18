class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.count(nums[i])) return nums[i];
            mpp[nums[i]]++;
        }
        return -1;

    }
};
