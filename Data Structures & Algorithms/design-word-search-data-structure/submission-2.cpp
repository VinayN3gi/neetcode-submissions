class Node
{
    public:
        Node *children[26];
        bool flag;

        Node()
        {
            for(int i=0;i<26;i++) children[i]=nullptr;
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
            for(char c:word)
            {
                if(temp->children[c-'a']==nullptr) 
                {
                    temp->children[c-'a']=new Node();
                }
                temp=temp->children[c-'a'];
            }
            temp->flag=true;
        }

        bool search(string word,int idx,Node *root)
        {   
            if(idx==word.size()) return root->flag;
            if(word[idx]=='.')
            {
                for(int i=0;i<26;i++)
                {
                    if(root->children[i]==nullptr) continue;
                    if(search(word,idx + 1 , root->children[i])) return true;
                }
                return false;
            }
            if(root->children[word[idx] - 'a']==nullptr) return false;
            return search(word,idx + 1 , root->children[word[idx] - 'a']);
        }
};
class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.addWord(word);
    }
    
    bool search(string word) {
        return t.search(word,0,t.root);
    }
};
