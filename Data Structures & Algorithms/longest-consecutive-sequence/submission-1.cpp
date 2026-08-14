class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(!mpp.count(nums[i]-1))
            {
                int count=0;
                int val=nums[i];
                while(mpp.count(val))
                {
                    val=val +1;
                    count++;
                    ans=max(ans,count);
                }
            }
        }

        return ans;
    }
};
