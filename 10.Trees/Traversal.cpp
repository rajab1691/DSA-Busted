//DFS
void inOrder(Node* root) {

	if (root == NULL)return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}
void preOrder(Node* root) {
	if (root == NULL)return;

	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node* root) {
	if (root == NULL)return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

//BFS
void leverOrder(Node* root) {

	if (root == NULL)
		return;

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {

		int size = q.size();
		while (size--) {

			Node* node = q.front();
			q.pop();
			cout << node->val << " ";

			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
	}
}
