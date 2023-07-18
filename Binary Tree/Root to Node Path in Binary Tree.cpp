vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    vector<string>ans;
    queue<pair<BinaryTreeNode<int>*,string>>q;
    q.push({root,""});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int>* node = it.first;
        string s = it.second;
        s += to_string(node->data) + " ";
        if(node->left){
            q.push({node->left,s});
        }
        if(node->right){
            q.push({node->right,s});
        }
        if(!node->left && !node->right){
            s.pop_back();
            ans.push_back(s);
        }
    }
    return ans;
}
