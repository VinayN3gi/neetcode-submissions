class Solution {
public:
    int exFirst(vector<int> &nums)
    {
        if (nums.size() <= 1) return 0;
        vector<int> seen(nums.size() + 1, 0);
        seen[0] = 0;
        seen[1] = 0;
        for(int i = 2; i <= nums.size(); i++)
        {
            seen[i] = max(seen[i-1], nums[i-1] + seen[i-2]);
        }
        return seen[nums.size()];
    }
    int exLast(vector<int> &nums)
    {
        if (nums.size() <= 1) return nums[0];
        vector<int> seen(nums.size() + 1, 0);
        seen[0] = 0;
        seen[1] = nums[0];
        for(int i = 2; i < nums.size(); i++)
        {
            seen[i] = max(seen[i-1], nums[i-1] + seen[i-2]);
        }
        return seen[nums.size() - 1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans = max(exFirst(nums), exLast(nums));
        return ans;
    }
};