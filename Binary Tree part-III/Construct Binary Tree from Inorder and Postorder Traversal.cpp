class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>&mp){
        if(is > ie && ps > pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-is;
        root->left = buildTree(postorder,ps,ps+numsLeft-1,inorder,is,inRoot-1,mp);
        root->right = buildTree(postorder,ps+numsLeft,pe-1,inorder,inRoot+1,ie,mp);

        return root;
    }
};
