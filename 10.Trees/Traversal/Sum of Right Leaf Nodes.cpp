/*
  Right leaf means two choice: do right opern first
  
*/
bool isLeaf(Node* root) {
	if (root and root->left == NULL and root->right == NULL)
		return true;
	return false;
}
Node* funcn(Node* root, int &sum) {
	if (root == NULL)
		return NULL;

	if (root->right and isLeaf(root->right)) {
		sum += root->right->data;
	}
	funcn(root->left, sum);
	funcn(root->right, sum);
	return root;
}
int rightLeafSum(Node* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	funcn(root, sum);
	return sum;
}
