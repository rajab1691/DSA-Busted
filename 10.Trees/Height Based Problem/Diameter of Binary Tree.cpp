/*
  Brute Force: Go to every nodes and cal left & right height and maximum for every node will be the diameter O(n^2)
  Better: cal depth at each step and take maximum: O(n)
*/
int dia(TreeNode* root, int &diameter) {
	if (root == NULL)
		return 0;
	int lh = dia(root->left, diameter);
	int rh = dia(root->right, diameter);
	diameter = max(diameter, lh + rh);
	return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode* root) {

	int diameter = 0;
	dia(root, diameter);
	return diameter;
}
