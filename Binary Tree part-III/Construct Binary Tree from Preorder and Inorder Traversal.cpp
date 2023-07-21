class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>&preorder,int ps,int pe,vector<int>&inorder,int is,int ie,map<int,int>&mp){
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - is;
        root->left = buildTree(preorder,ps+1,ps+numsLeft,inorder,is,inRoot-1,mp);
        root->right = buildTree(preorder,ps+numsLeft+1,pe,inorder,inRoot+1,ie,mp); 

        return root; 
    }
};
