/*
     Thinking approach: (Post order)
     1. When we are at root then we know that we have to go right first.
     2. So check 1st that is root has right children? if it is then check if it leaf node?
     3. If it is leaf node then add to sum then do normal post order 
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
