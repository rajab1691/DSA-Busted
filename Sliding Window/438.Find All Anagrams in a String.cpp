/*
  Input: s = "cbaebabacd", p = "abc"
  Output: [0,6]
  Explanation:
  The substring with start index = 0 is "cba", which is an anagram of "abc".
  The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

/*
  1. Use Sliding Window technique
  2. and for every window check into count array that their frequency are same
  T.C- O(l1+26*(l2-l1))
*/
class Solution {
  public:

    bool allZero(vector<int>&count) {
      for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
          return false;
      }
      return true;
    }
  vector<int>findAnagrams(string s, string p) {
    vector<int>ans;

    int n = p.length();
    int m = s.length();

    if (n > m)
      return ans;

   vector<int>count(26,0);

    for (int i = 0; i < n; i++) {
      count[p[i] - 'a']++;
      count[s[i] - 'a']--;
    }
    if (allZero(count)) {
      ans.push_back(0);
    }

    for (int i = n; i < m; i++) {
      count[s[i] - 'a']--;
      count[s[i - n] - 'a']++;
      if (allZero(count)) {
        ans.push_back(i - n + 1);
      }
    }
    return ans;
  }
};
