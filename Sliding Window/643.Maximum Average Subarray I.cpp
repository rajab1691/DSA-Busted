/*
  1. Simple Sliding window
  T.C-O(n)
*/
class Solution {
  public:
    double findMaxAverage(vector<int>&nums, int k) {

      double ans = 0.0;

      int n = nums.size();
      int sum = 0;

      for (int i = 0; i < k; i++) {
        sum += nums[i];
      }
      ans = (double) sum / k;

      for (int i = k; i < n; i++) {
        sum += (nums[i] - nums[i - k]);
        double val = (double) sum / k;
        ans = max(ans, val);
      }
      return ans;
    }
};
