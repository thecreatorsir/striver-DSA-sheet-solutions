// dfs way
class Solution {
public: 
    unordered_map<Node*,Node*> mp;
    void dfs(Node *node){
        Node * copy = new Node(node->val);
        mp[node] =  copy;
        for(auto x:node->neighbors){
            if(mp.find(x)==mp.end()){
                dfs(x);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        dfs(node);
        for(auto x:mp){
            Node *real=x.first,*newnode=x.second;
            for(auto v:real->neighbors)
                newnode->neighbors.push_back(mp[v]);
        }
      return mp[node];
    }
};

//bfs way
Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return node;
        }
        if(node->neighbors.size() == 0){
            return new Node(node->val);
        }
        map<Node*, Node*> mp;
        
        Node* copies;
        copies = new Node(node->val);
        mp[node] = copies;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            for(Node* n: tmp->neighbors){
                if(mp.find(n) == mp.end()){
                    mp[n] = new Node(n->val);
                    q.push(n);
                }
                mp[tmp]->neighbors.push_back(mp[n]);
            }
        }
        
        return copies;
    }