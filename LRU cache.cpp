//will act as cache memory
class DLL{
    public:
    int value;
    int key;
    DLL *next=NULL;
    DLL * prev=NULL;
    DLL(int k,int v)
    {
        value=v;
        key=k;
    }
};

class LRUCache {
     int n;
    //to store key and value (node)
    map<int,DLL*> m;
	 
    // dummy node enclose the actual values
    DLL* head=new DLL(-1,-1);
    DLL* tail=new DLL(-1,-1);
	
public:
       LRUCache(int capacity) {
        n=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    //insertion is alway done at front befone dummy head
    void addnode(DLL* node)
    {
      node->next=head->next;
      head->next->prev=node;
      node->prev=head;
      head->next=node;
      m[node->key]=node;  
    }
	
    //removal from the list and the hashmap
    void remove(DLL* node)
    {   DLL *temp = node->prev;
        temp->next = node->next;
        node->next->prev = temp;
        m.erase(node->key);       
    }

    //if the element if present then return it and place it to the front of the list
    int get(int key) {
        if(m.find(key)!=m.end()){
            DLL* node=m[key];
            remove(node);
            addnode(node);
            return node->value;
        }
        return -1;
    }
    
    //if the element is present the update it by new node both in list and hashmap
    //else if space present the add else remove least recent use and newnode to list
    void put(int key, int value) {
        DLL * newnode=new DLL(key,value);
            if(m.find(key)!=m.end()) {    
                DLL *node = m[key];
                remove(node);   
           }else{
            if(m.size()>=n){
                DLL * tt=tail->prev; 
                remove(tt);   
            }  
        }
        addnode(newnode);
    }
};
