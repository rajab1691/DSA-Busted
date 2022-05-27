/*
  Prob: Given an array of distinct integers, and target return a list of all unique combinations, which sums up to target
  Input: candidates = [2,3,6,7], target = 7
  Output: [[2,2,3],[7]]
*/

/*
    Since the problem is to get all the possible results, not the best or the number of result, 
    thus we don’t need to consider DP(dynamic programming), Backtracking is needed to handle it.
    
    Time Complexity=O(k*2^n)
*/
vector<vector<int>>ans;
vector<vector<int>> combinationSum(vector<int>&a, int t) {
	vector<int>temp;
	helper(0, a, t, temp);
	return ans;
}

void helper(int idx, vector<int>&a, int t, vector<int>&temp) {

	if (idx == a.size())
		return;

	if (t == 0) {
		ans.push_back(temp);
		return;
	}
	if (t < 0) {
		return;
	}

	//pick
	temp.push_back(a[idx]);
	helper(idx, a, t - a[idx], temp);
	temp.pop_back();


	//not pick
	helper(idx + 1, a, t, temp);
}

