 /*
 	The idea is based on threaded binary tree.
        Morris Traversal:we can traverse the tree without using stack and recursion
        Steps-1: if (curr->left) is not NULL, then go to the rightmost child of (curr->left)
                  1.if not connected with its root then connect and go to left again
                  2.if connected then disconnect push that into our ans and go to right
                  
        Steps-2: if (curr->left) is  NULL, then in Inorder we need to push the root so just push the root and go right
        
        T.C-O(n)
        S.C-const 
*/
vector<int> inorderTraversal(TreeNode* root) {

	vector<int>ans;

	TreeNode* curr = root;

	while (curr) {

		if (curr->left == NULL) {
			ans.push_back(curr->val);
			curr = curr->right;
		} else {
      
			TreeNode* prev = curr->left;

			while (prev->right and prev->right != curr) {
				prev = prev->right;
			}

			if (prev->right == NULL) {
				prev->right = curr;
				curr = curr->left;
			} else {
				prev->right = NULL;
				ans.push_back(curr->val);
				curr = curr->right;
			}
		}
	}

	return ans;
}
