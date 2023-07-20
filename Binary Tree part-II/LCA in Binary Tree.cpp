class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root == p || root == q){
            return root;
        }
        TreeNode* leftlca=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightlca=lowestCommonAncestor(root->right,p,q);
        if(!rightlca){
            return leftlca;
        }
        if(!leftlca){
            return rightlca;
        }
        return root;
    }
};
