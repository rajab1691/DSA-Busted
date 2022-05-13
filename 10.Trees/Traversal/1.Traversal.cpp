/* 
 All traversals has:
   Time complexity: O(n) 
   Space complexity: O(n)
*/
 

//Inorder Traversal
 vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
           inorderTraversal(root->left);
           cout<<(root->val)<<" ";
           inorderTraversal(root->right);
        }
 }

//Preorder Traversal
 vector<int> preorderTraversal(TreeNode* root) {
        if(root!=NULL){
           cout<<(root->val)<<" ";
           preorderTraversal(root->left);
           preorderTraversal(root->right);
        }
 }

 //Postorder Traversal
 vector<int> postorderTraversal(TreeNode* root) {
        if(root!=NULL){
           postorderTraversal(root->left);
           postorderTraversal(root->right);
           cout<<(root->val)<<" ";
        }
 }

//LevelOrder Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>res;
        if(root==NULL)return res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            vector<int>ans;
            int size=q.size();
            
            while(size--){
              TreeNode* node=q.front();
              q.pop();
              ans.push_back(node->val);
              if(node->left){
                  q.push(node->left);
              }
              if(node->right){    
                  q.push(node->right);
              }
          }
            res.push_back(ans);
       }
       return res;
    }
