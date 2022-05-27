/*
  Same as C Sum-1, Just extra check that temp size must be equal to k and we can't take element twice
  
  Time Complexity :- O(K * 9^K)
  Space Complexity :- O(K)
*/
vector<vector<int>>ans;
vector<vector<int>> combinationSum3(int k, int t) {

	vector<int>a;
	for (int i = 1; i <= 9; i++)
		a.push_back(i);

	vector<int>temp;
	helper(0, a, t, temp, k);
	return ans;
}
void helper(int idx, vector<int>&a, int t, vector<int>&temp, int k) {

	if (t == 0 and temp.size() == k) {
		ans.push_back(temp);
		return;
	}

	if (idx == a.size() or t<0 or temp.size()>k)
		return;

	//pick
	temp.push_back(a[idx]);
	helper(idx + 1, a, t - a[idx], temp, k);
	temp.pop_back();

	//not pick
	helper(idx + 1, a, t, temp, k);
}
