//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

/*
  1.insert every string in trie and also maintain a count variable for each char in trie
  2.sum of count for each trie string is the ans
*/

class Node {
public:
	char data;
	unordered_map<char, Node*>children;
	int cnt = 0;

	Node() {}
	Node(char d) {
		data = d;
	}
};
class Trie {
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	Node* getTrie() {
		return root;
	}
	void insert(string word) {

		Node* temp = root;
		for (int i = 0; i < word.length(); i++) {
			char ch = word[i];
			if (temp->children.count(ch) == 0) {
				temp->children[ch] = new Node(ch);
			}
			temp->children[ch]->cnt++;
			temp = temp->children[ch];
		}
	}
};
class Solution {
public:
	vector<int> sumPrefixScores(vector<string>& words) {
		int n = size(words);
		Trie* t = new Trie();
		for (int i = 0; i < n; i++) {
			t->insert(words[i]);
		}
		vector<int>ans(n, 0);

		for (int i = 0; i < n; i++) {
			int cntt = 0;
			string s = words[i];
			Node* temp = t->getTrie();
			for (int j = 0; j < s.length(); j++) {
				cntt += temp->children[s[j]]->cnt;
				temp = temp->children[s[j]];
			}
			ans[i] = cntt;
		}
		return ans;
	}
};

