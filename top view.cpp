vector<int> topView(struct Node *root){
  queue<pair<Node *,int>> q;
  map<int,int> mp;
  vector<int> v;
  q.push({root,0});
  while(!q.empty()){
      pair<Node*,int> temp = q.front();
      q.pop();
      if(!mp.count(temp.second)){
          mp[temp.second] = temp.first->data;
      }
      if(temp.first->left){
          q.push({temp.first->left,temp.second-1});
      }
      if(temp.first->right){
          q.push({temp.first->right,temp.second+1});
      }
  }
  for(auto x:mp){
      v.push_back(x.second);
  }
  return v;
}