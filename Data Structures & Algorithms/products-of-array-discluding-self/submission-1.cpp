class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l1;
        int val=1;
        for(int i=0;i<nums.size();i++)
        {
            l1.push_back(val);
            val=val * nums[i];
        }
        vector<int> l2;
        val=1;
        for(int i=nums.size() - 1 ; i>=0;i--)
        {
            l2.push_back(val);
            val=val * nums[i];
        }
        reverse(l2.begin(),l2.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(l1[i] * l2[i]);
        }
        return ans;
    }
};
