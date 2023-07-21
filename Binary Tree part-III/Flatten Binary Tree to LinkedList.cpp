class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        // Approach 1
        // if(root == NULL) return;
        // flatten(root->right);
        // flatten(root->left);

        // root->right = prev;
        // root->left = NULL;
        // prev = root;
        // Approach 2
        if(!root) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }
};
