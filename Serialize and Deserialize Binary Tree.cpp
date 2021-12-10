class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if(!root){
            return "x";
        }
        return to_string(root->val) + "," + serialize(root->left)+","+serialize(root->right);
    }
    
    TreeNode* build(vector<string> &v,int &i){
         if(i == v.size()){   
            return NULL;
         }
        string val = v[i++];
          if(val == "x"){   
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = build(v, i);
        node->right = build(v, i);
        return node;
   }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;  //store the node array

        stringstream ss(data);  //use a string stream to saperate the node
        string node;
        while(getline(ss,node,',')) v.push_back(node);
        int i=0;
        return build(v, i);
        }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));