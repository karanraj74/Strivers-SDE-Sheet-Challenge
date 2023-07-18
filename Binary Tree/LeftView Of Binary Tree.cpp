vector<int> leftView(Node *root)
{
   // Your code here
   queue<Node*>q;
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    q.push(root);
    
    
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==0){
                ans.push_back(curr->data);
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return ans;
}
