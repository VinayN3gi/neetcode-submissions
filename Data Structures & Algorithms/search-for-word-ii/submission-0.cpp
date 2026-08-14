class Node
{
    public:
        Node* children[26];
        bool isEnd;
        string word;
        Node()
        {
            for(int i=0;i<26;i++) children[i]=nullptr;
            isEnd=false;
            word="";
        }
};
class Trie
{
    public:
        Node *root;
        Trie()
        {
            root=new Node();
        }

        void insert(string word)
        {
            Node *temp=root;
            for(int i=0;i<word.size();i++)
            {
                int idx=word[i] - 'a';
                if(temp->children[idx]==nullptr)
                {
                    temp->children[idx]=new Node();
                }
                temp=temp->children[idx];
            }
            temp->isEnd=true;
            temp->word=word;
        }

        void search(vector<vector<char>> &board,Node *root,int i,int j,vector<string> &ans)
        {
            if(root==nullptr) return ;
            char x=board[i][j];
            if(root->children[x-'a']==nullptr) return ;
            root=root->children[x-'a'];
            if(root->isEnd)
            {
                ans.push_back(root->word);
                root->isEnd=false;
            }

            board[i][j]='#';

            vector<int> r1={-1,1,0,0};
            vector<int> r2={0,0,-1,1};
            for(int k=0;k<4;k++)
            {
                int row=i + r1[k];
                int col= j + r2[k];
                if(row<0 || row>=board.size() || col<0 
                || col>=board[0].size() || board[row][col]=='#') continue;
                search(board,root,row,col,ans);
            }
            board[i][j]=x;
        }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie T;
        for(int i=0;i<words.size();i++) T.insert(words[i]);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                T.search(board,T.root,i,j,ans);
            }
        }
        return ans;
    }
};
