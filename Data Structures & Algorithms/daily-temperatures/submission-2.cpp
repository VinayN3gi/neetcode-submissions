class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> ans(temp.size(),0);
        for(int i=0;i<temp.size();i++)
        {
            if(stk.empty() || temp[i] <= temp[stk.top()])
            {
                stk.push(i);
            }
            else if(temp[stk.top()] < temp[i])
            {
                //int count = 1;
                while(!stk.empty() && temp[stk.top()] < temp[i])
                {
                    int val=stk.top();stk.pop();
                    ans[val]=i - val ;
                }
                stk.push(i);
            }
        }
        return ans;
    }
};
