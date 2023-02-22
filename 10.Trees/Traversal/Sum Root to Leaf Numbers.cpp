// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
/*
 Return the total sum of all root-to-leaf numbers
  1. Normal preorder traversal
  2. Take care to add ans to result when it is a leaf node
  3. Remember to pop_back the element after traversal is over
  
  T.C & S.C -O(n) 
*/
void sum(TreeNode* root,int &res,int &curr){
        
        if(root==NULL)return;
        
        curr=curr*10+root->val;
        sum(root->left,res,curr);
        sum(root->right,res,curr);
        if(root->left==NULL and root->right==NULL)
            res+=curr;
        
        curr/=10;
        
}
    int sumNumbers(TreeNode* root) {
        int res=0;
        int curr=0;
        sum(root,res,curr);
        return res;
}
