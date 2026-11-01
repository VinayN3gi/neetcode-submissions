class Node
{
public:
    Node* children[26];
    bool flag;
    Node()
    {
        for(int i=0;i<26;i++) children[i]=nullptr;
        flag=false;
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
            if(temp->children[word[i] - 'a']==nullptr) temp->children[word[i] - 'a']=new Node();
            temp=temp->children[word[i] - 'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node *temp=root;
        for(char &c:word)
        {
            if(temp->children[c - 'a']==nullptr) return false;
            temp=temp->children[c - 'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
        for(char &c:prefix)
        {
            if(temp->children[c - 'a']==nullptr) return false;
            temp=temp->children[c - 'a'];
        }
        if(temp!=nullptr) return true;
        else return false;
    }
};
