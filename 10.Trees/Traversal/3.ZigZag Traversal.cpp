/*
  Approach 1: Idea is to use two stacks
  T.C & S.C -O(n)
*/
vector <int> zigZagTraversal(Node* root)
{
	stack<Node*>st1, st2;
	st1.push(root);
	vector<int>ans;
	while (!st1.empty() or !st2.empty()) {

		while (!st1.empty()) {
			Node* node = st1.top();
			st1.pop();
			ans.push_back(node->data);
			if (node->left) {
				st2.push(node->left);
			}
			if (node->right) {
				st2.push(node->right);
			}
		}
		while (!st2.empty()) {
			Node* node = st2.top();
			st2.pop();
			ans.push_back(node->data);

			if (node->right) {
				st1.push(node->right);
			}
			if (node->left) {
				st1.push(node->left);
			}
		}
	}
	return ans;
}

/*
  Approach-2: Using deque
  level : odd=> pop->front and push->back (right,left)
          even=> pop->back and push->front (left,right)
*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>>ans;
	if (root == NULL)return ans;

	deque<TreeNode*>q;
	vector<int>v;
	q.push_back(root);
	v.push_back(root->val);
	ans.push_back(v);
	v.clear();
	int l = 1;
	TreeNode* temp = q.front();

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			//popping
			if (l % 2) {
				temp = q.front();
				q.pop_front();
			} else {
				temp = q.back();
				q.pop_back();
			}
			//pushing
			if (l % 2) {
				if (temp->right) {
					q.push_back(temp->right);
					v.push_back(temp->right->val);
				}
				if (temp->left) {
					q.push_back(temp->left);
					v.push_back(temp->left->val);
				}
			} else {
				if (temp->left) {
					q.push_front(temp->left);
					v.push_back(temp->left->val);
				}
				if (temp->right) {
					q.push_front(temp->right);
					v.push_back(temp->right->val);
				}
			}
		}
		l++;
		if (v.size())
			ans.push_back(v);
		v.clear();
	}
	return ans;
}
