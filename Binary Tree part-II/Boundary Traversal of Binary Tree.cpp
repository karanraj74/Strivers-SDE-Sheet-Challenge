class Solution {
private:
    bool isLeaf(Node* node){
        if(!node->left && !node->right) return true;
        return false;
    }
    void addLeftNodes(Node* root,vector<int>&ans){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }    
    void addLeaves(Node* root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right,ans);
    }
    void addRightNodes(Node* root,vector<int>&ans){
        Node* curr = root->right;
        stack<int>st;
        while(curr){
            if(!isLeaf(curr)) st.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftNodes(root,ans);
        addLeaves(root,ans);
        addRightNodes(root,ans);
        return ans;
    }
};
