class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int len = nums.size();
        // dp[i]: all before i (not including i) can form a viable partition
        vector<bool> dp(len + 1);
        dp[0] = true;
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && dp[i - 1]) {
                dp[i + 1] = true;
            } else if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && dp[i - 2]) {
                dp[i + 1] = true;
            } else if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1 && dp[i - 2]) {
                dp[i + 1] = true;
            }
        }
        return dp[len];
    }
};