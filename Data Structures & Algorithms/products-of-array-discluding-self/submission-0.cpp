class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> arr1;
        int acc=1;
        for(int i=0;i<nums.size();i++)
        {
            arr1.push_back(acc);
            acc=acc * nums[i];
        }
        acc=1;
        vector<int> arr2(nums.size(),0);
        for(int i=nums.size()-1 ;i >=0;i--)
        {
            arr2[i]=acc;
            acc=acc * nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(arr1[i] * arr2[i]);
        }
        return ans;
    }
};
