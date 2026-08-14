class Node
{
public:
    Node *children[26];
    bool isEnd;
    Node(){
        for(int i=0;i<26;i++) children[i]=nullptr;
        isEnd=false;
    }
};
class PrefixTree {
public:
    Node *root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i] - 'a';
            if(temp->children[idx]==nullptr) return false;
            else temp=temp->children[idx];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int idx=prefix[i] - 'a';
            if(temp->children[idx]==nullptr) return false;
            else temp=temp->children[idx];
        }
        return true;
    }
};
