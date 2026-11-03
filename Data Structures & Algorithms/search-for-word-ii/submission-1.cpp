vector<int> row1={0,0,-1,1};
vector<int> row2={-1,1,0,0};
class Node
{
    public:
    Node *children[26];
    bool flag;
    string word;
    public:
        Node()
        {
            for(int i=0;i<26;i++)
            {
                children[i]=nullptr;
            }
            flag=false;
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

        void addWord(string word)
        {
            Node *temp=root;
            for(char c : word)
            {
                if(temp->children[c - 'a']==nullptr)
                {
                    temp->children[c - 'a'] = new Node();
                }
                temp=temp->children[c - 'a'];
            }
            temp->flag=true;
            temp->word=word;
        }

        void dfs(vector<vector<char>> &board,
        vector<vector<int>> &seen,vector<string> &ans,unordered_set<string> &words,Node *temp,int row,int col)
        {
            if(temp->flag==true && words.count(temp->word))
            {
                ans.push_back(temp->word);
                words.erase(temp->word);
            }

            for(int i=0;i<4;i++)
            {
                int newr=row + row1[i];
                int newc=col + row2[i];

                if(newr<0 || newr>=board.size() || 
                newc<0 || newc>=board[0].size() || 
                seen[newr][newc] || temp->children[board[newr][newc] - 'a'] == nullptr) continue;

                seen[newr][newc]=1;
                dfs(board,seen,ans,words,temp->children[board[newr][newc] - 'a'],newr,newc);
                seen[newr][newc]=0;
            }
        }   

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> word_set(words.begin(),words.end());
        vector<string> ans;
        Trie t;
        for(int i=0;i<words.size();i++) t.addWord(words[i]);
        vector<vector<int>> seen(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(t.root->children[board[i][j] - 'a']!=nullptr)
                {    seen[i][j]=1;
                    t.dfs(board,seen,ans,word_set,t.root->children[board[i][j] - 'a'],i,j);
                    seen[i][j]=0;
            }
            }
        }

        return ans;
    }
};
