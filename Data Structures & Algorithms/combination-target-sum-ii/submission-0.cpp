class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &cand,int target,
    vector<int> seen,int sum,vector<int> temp,int curr)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return ;
        }
        if(sum > target || curr > cand.size()) return ;
        for(int i=curr;i<cand.size();i++)
        {
            if(i>0 && (!seen[i-1] && cand[i]==cand[i-1])) continue;
            seen[i]=1;
            temp.push_back(cand[i]);
            solve(ans,cand,target,seen,sum + cand[i],temp,i+1);
            seen[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<int> seen(cand.size(),0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,cand,target,seen,0,temp,0);
        return ans;
    }
};
