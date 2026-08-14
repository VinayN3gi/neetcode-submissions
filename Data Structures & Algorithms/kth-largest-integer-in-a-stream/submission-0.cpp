class Compare
{
public:
    bool operator()(int a,int b)
    {
        return a > b;
    }
};
class KthLargest {
public:
    priority_queue<int,vector<int>,Compare> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size)
        {
            pq.pop();
        }
        return pq.top();
    }
};
