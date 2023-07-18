
vector<int> getPreOrderTraversal(TreeNode *root)
{
     vector<int>preorder;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
