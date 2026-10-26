class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int ele : st)
        {
            if(st.count(ele - 1)) continue;
            else
            {
                int count=0;
                int val=ele;
                while(st.count(val))
                {
                    count++;
                    val++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
