class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left=1;
        int leftMax=height[0];
        int rightMax=height[height.size()-1];
        int right=height.size() - 2;
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
