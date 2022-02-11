/*
  Input: s1 = "ab", s2 = "eidbaooo"   
  Output: true
  Explanation: s2 contains one permutation of s1 ("ba").
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
  bool checkInclusion(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();
    if (n > m)
      return false;

    vector<int>count(26, 0);

    for (int i = 0; i < n; i++) {
      count[s1[i] - 'a']++;
      count[s2[i] - 'a']--;
    }
    if (allZero(count))
      return true;

    for (int i = n; i < m; i++) {
      count[s2[i] - 'a']--;
      count[s2[i - n] - 'a']++;
      if (allZero(count))
        return true;
    }
    return false;
  }
};
