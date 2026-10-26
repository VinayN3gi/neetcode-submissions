class Greater
{
public:
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second > b.second ;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Greater> pq;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
        for(auto &[val,freq] : mpp)
        {
            pq.push({val,freq});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
