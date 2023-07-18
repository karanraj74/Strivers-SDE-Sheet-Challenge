class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        // {node , {vertical , level} }  
        queue<pair<TreeNode*,pair<int,int>>>q;
        // vertical -> level -> {nodes}
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int ver = it.second.first;
            int lev = it.second.second;
            mp[ver][lev].insert(node->val);
            if(node->left){
                q.push({node->left,{ver-1,lev+1}});
            }
            if(node->right){
                q.push({node->right,{ver+1,lev+1}});
            }
        }
        for(auto it : mp){
            vector<int>col;
            for(auto i : it.second){
                col.insert(col.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
