class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int l = it.second;
            
            mp[l] = node->data;
            if(node->left){
                q.push({node->left,l-1});
            }
            if(node->right){
                q.push({node->right,l+1});
            }
        }
        vector<int>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};