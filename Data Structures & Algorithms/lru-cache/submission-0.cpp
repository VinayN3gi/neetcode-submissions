class Node
{
    public:
        Node *next;
        Node *prev;
        int key;
        int val;

        Node(int k , int v)
        {
            key=k;
            val=v;
            next=nullptr;
            prev=nullptr;
        }
};
class LRUCache {
public:
    int cap;
    Node *head;
    Node *tail;
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(Node* n)
    {
        n->next=head->next;
        head->next->prev=n;
        head->next=n;
        n->prev=head;
    }
    void remove(Node *n)
    {
        n->prev->next=n->next;
        n->next->prev=n->prev;
        n->prev=nullptr;
        n->next=nullptr;
    }
    
    int get(int key) {
        if(mpp.count(key))
        {
            remove(mpp[key]);
            add(mpp[key]);
            return mpp[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.count(key))
        {
            Node *n=mpp[key];
            n->val=value;
            remove(n);
            add(n);
            return ;
        }

        Node *newNode=new Node(key,value);
        mpp[key]=newNode;
        add(newNode);
        if(mpp.size() > cap)
        {
            Node *lru=tail->prev;
            remove(lru);
            mpp.erase(lru->key);
        }

    }
};
