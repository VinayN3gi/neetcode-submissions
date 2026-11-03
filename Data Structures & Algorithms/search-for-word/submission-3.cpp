class Solution {
public:
    vector<int> row1={-1,1,0,0};
    vector<int> row2={0,0,-1,1};
    bool solve(vector<vector<char>> &board,
    string word,int idx,vector<vector<int>> &seen,int row,int col)
    {
        if(idx==word.size()) return true;
        if(idx > word.size()) return false;
        for(int i=0;i<row1.size();i++)
        {
            int newr=row + row1[i];
            int newc=col + row2[i];

            if(newr<0 || newr>=board.size() || 
            newc<0 || newc>=board[0].size() || seen[newr][newc] || board[newr][newc]!=word[idx]) continue;
            seen[newr][newc]=1;
            if(solve(board,word,idx + 1, seen , newr,newc)) return true;
            seen[newr][newc]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> seen(board.size(),vector<int>(board[0].size() , 0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    seen[i][j]=1;
                    if(solve(board,word,1,seen,i,j)) return true;
                    seen[i][j]=0;
                }
            }
        }
        return false;
    }
};
