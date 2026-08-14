class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> stk;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int idx = stk.top();
                stk.pop();

                int width;

                if(stk.empty())
                    width = i;
                else
                    width = i - stk.top() - 1;

                ans = max(ans, heights[idx] * width);
            }

            stk.push(i);
        }

        // remaining bars
        while(!stk.empty())
        {
            int idx = stk.top();
            stk.pop();

            int width;

            if(stk.empty())
                width = n;
            else
                width = n - stk.top() - 1;

            ans = max(ans, heights[idx] * width);
        }

        return ans;
    }
};