/*
  Do normal DFS, whenever a node is a leaf node push the sum to vector
*/
void dfs(Node* root, int currSum, vector<int>&pathSum) {

	if (root == NULL)
		return;

	currSum += root->data;
	if (root->left == NULL and root->right == NULL) {
		pathSum.push_back(currSum);
		return;
	}

	dfs(root->left, currSum, pathSum);
	dfs(root->right, currSum, pathSum);
	return;
}
void hasPathSum(Node *root, int s) {

	int currSum = 0;

	vector<int>pathSum;

	dfs(root, currSum, pathSum);

	for (int i = 0; i < pathSum.size(); i++) {
		cout<<pathSum[i]<<" ";
	}
}
