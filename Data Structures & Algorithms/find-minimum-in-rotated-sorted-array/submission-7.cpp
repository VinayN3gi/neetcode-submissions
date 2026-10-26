class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1) return nums[0];
        int l=0;
        int r=nums.size() - 1;
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid= (l + r )/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[mid])
            {
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return ans;
    }
};
