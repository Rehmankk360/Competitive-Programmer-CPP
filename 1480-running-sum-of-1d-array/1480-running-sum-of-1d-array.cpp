class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rs(nums.size());
        int s = 0;
        for(int i = 0; i<nums.size(); i++){
            s+=nums[i];
            rs[i] = s;
        }
        return rs;
    }
    
};