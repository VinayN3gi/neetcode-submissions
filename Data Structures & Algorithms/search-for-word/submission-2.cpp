class Solution {
public:
    vector<int> r1={-1,1,0,0};
    vector<int> r2={0,0,-1,1};
    bool solve(vector<vector<char>> &board,vector<vector<int>> &seen,
    string word,int row,int col,int idx)
    {
        if(idx==word.size()) return true;
        bool ans=false;
        for(int i=0;i<4;i++)
        {
            int newr=row + r1[i];
            int newc=col + r2[i];
            if(newr<0 || newr>=board.size() || newc<0 || 
            newc>=board[0].size() || seen[newr][newc] || board[newr][newc]!=word[idx]) continue;
            seen[newr][newc]=1;
            ans=ans || solve(board,seen,word,newr,newc,idx+1);
            seen[newr][newc]=0;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>> seen(board.size(),vector<int>(board[0].size(),0));
                    seen[i][j]=1;
                    if(solve(board,seen,word,i,j,1)) return true;
                }
            }
        }

        return false;
    }
};
