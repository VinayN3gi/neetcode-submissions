class Node
{
public:
    Node *children[26];
    bool isEnd;
    Node()
    {
        for(int i=0;i<26;i++)  children[i]=nullptr;
        isEnd=false;
    }
};
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
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
    }


    bool solve(string word,int idx,Node *root)
    {
        if(idx==word.size()) return root->isEnd;
        
        if(word[idx]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(root->children[i]!=nullptr)
                {
                    if(solve(word,idx + 1 , root->children[i])) return true;
                }
            }
            return false;
        }
        int x=word[idx] - 'a';
        if(root->children[x]==nullptr) return false;
        return solve(word,idx+1,root->children[x]);
    }
    
    bool search(string word) {
        return solve(word,0,root);
    }
};
