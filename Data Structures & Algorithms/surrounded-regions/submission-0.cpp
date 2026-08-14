class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O') {
                q.push({0,i});
                board[0][i]='1';
            }
            if(board[board.size()-1][i]=='O') {
                q.push({board.size() - 1 , i});
                board[board.size() - 1][i]='1';
            }
        }

        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                board[i][0]='1';
            }
            if(board[i][board[0].size() - 1]=='O')
            {
                q.push({i,board[0].size() - 1});
                board[i][board[0].size() -1 ]='1';
            }
        }

        vector<int> r1={-1,1,0,0};
        vector<int> r2={0,0,-1,1};
        
        while(!q.empty())
        {
            auto x=q.front();q.pop();
            for(int i=0;i<4;i++)
            {
                int newr=x.first + r1[i];
                int newc=x.second + r2[i];
                if(newr<0 || newr>=board.size() || newc<0 || 
                newc>=board[0].size() || board[newr][newc]=='X' 
                || board[newr][newc]=='1') continue;
                q.push({newr,newc});
                board[newr][newc]='1';
            }
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='1') board[i][j]='O';
            }
        }

    }
};
