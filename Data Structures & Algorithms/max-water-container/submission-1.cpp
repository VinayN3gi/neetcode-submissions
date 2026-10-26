class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int ans=INT_MIN;
        while(l<r)
        {
            int val=(r - l) * min(heights[l],heights[r]);
            ans=max(ans,val);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
