class LRUCache {
public:
class Node{
    public:
    int key,val;
    Node* prev;
    Node* next;
    
    Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
};
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
unordered_map<int,Node*> m;
int limit;
void addNode(Node* newNode){
    Node* oldnext=head->next;
    head->next=newNode;
    oldnext->prev = newNode;
    newNode->next=oldnext;
    newNode->prev=head;

}
void deleteNode(Node* oldnode){
    Node* oldprev=oldnode->prev;
    Node* oldnext=oldnode->next;
    oldprev->next=oldnext;
    oldnext->prev=oldprev;
}

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansnode=m[key];
        int ans=ansnode->val;
        m.erase(key);
        deleteNode(ansnode);
        addNode(ansnode);
        m[key]=ansnode;
        return ans;
    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            Node* oldnode=m[key];
            deleteNode(oldnode);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode=new Node(key,val);
        addNode(newNode);
        m[key]=newNode;
    }
};
