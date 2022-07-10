/*
  Traverse left ,then leaves then right(in rev) 
*/


bool isLeaf(Node* root) {
	if (root->left == NULL and root->right == NULL)
		return true;
	return false;
}
void leftBoun(Node *root, vector<int>&ans) {

	Node* curr = root->left;

	while (curr) {
		if (!isLeaf(curr)) {
			ans.push_back(curr->data);
		}
		if (curr->left) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}
}
void leaves(Node *root, vector<int>&ans) {
	if (root == NULL)
		return;

	if (isLeaf(root)) {
		ans.push_back(root->data);
		return;
	}

	leaves(root->left, ans);
	leaves(root->right, ans);
}
void rightBoun(Node *root, vector<int>&ans) {
	Node* curr = root->right;
	vector<int>temp;

	while (curr) {
		if (!isLeaf(curr)) {
			temp.push_back(curr->data);
		}
		if (curr->right) {
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		ans.push_back(temp[i]);
	}
}
vector <int> boundary(Node *root)
{
	if (root == NULL)return {};
	vector<int>ans;

	if (!isLeaf(root))
		ans.push_back(root->data);

	leftBoun(root, ans);
	leaves(root, ans);
	rightBoun(root, ans);
	return ans;
}
