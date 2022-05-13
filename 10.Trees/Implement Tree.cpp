class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		left = right = NULL;
	}
};
void printTreePre(Node* root) {

	if (root == NULL)return;

	cout << root->val << " ";
	printTreePre(root->left);
	printTreePre(root->right);
}

int32_t main() {

	Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	printTreePre(root);
}
