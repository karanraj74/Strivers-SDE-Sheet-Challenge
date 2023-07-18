class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long ans = 0;
        while(!q.empty()){
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans,end-start+1);

            for(int i=0;i<n;i++){
                pair<TreeNode*,int>p = q.front();
                TreeNode* curr = p.first;
                long idx = p.second;
                q.pop();
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx+2});
                }
            }
        }
        return ans;
    }
};
