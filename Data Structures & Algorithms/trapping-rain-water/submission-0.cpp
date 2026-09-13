class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left=0;
        int leftMax=0;
        int rightMax=0;
        int right=height.size() - 1;
        while(left <= right)
        {
            if(leftMax < rightMax)
            {
                leftMax=max(leftMax,height[left]);
                ans=ans + (leftMax - height[left]);
                left++;
            }
            else
            {
                rightMax=max(rightMax,height[right]);
                ans=ans + (rightMax - height[right]);
                right--;
            }
        }
        return ans;
    }
};
