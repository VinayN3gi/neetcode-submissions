class Compare
{
    public:
        bool operator()(int a , int b)
        {
            return a > b;
        }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,Compare> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
