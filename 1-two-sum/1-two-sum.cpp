class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> h;
        for(int i = 0 ; i < nums.size(); i++){
            int s=target-nums[i];
            if(h[nums[i]] != 0) {
                return{i, h[nums[i]]-1};
                                }
            h[s] = i+1;
        }
        return {0};
    }
};