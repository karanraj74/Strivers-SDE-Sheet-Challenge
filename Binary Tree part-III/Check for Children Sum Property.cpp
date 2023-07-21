bool ans = true;
int solve(Node* root){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return root->data;
    
    int leftChild = solve(root->left);
    int rightChild = solve(root->right);
    if(leftChild + rightChild != root->data){ans = false;}
    return root->data;

}
bool isParentSum(Node *root){
    // Write your code here.
    solve(root);
    return ans; 
}
