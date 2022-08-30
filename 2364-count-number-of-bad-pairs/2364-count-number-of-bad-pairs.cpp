class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long size = nums.size();
        unordered_map<int, long long> goodPairs;
        
        for(int i = 0; i < size; i++){
            if(goodPairs.find(nums[i]-i) == goodPairs.end())
                goodPairs[nums[i] - i] = 0;
            else
                goodPairs[nums[i] - i]++;
        }
        
        long long goodCount = 0;
        
        for(auto x : goodPairs){
            goodCount += (x.second*(x.second+1)/2);
        }
        
        long long badCount = (size*(size-1)/2) - goodCount;
        
        return badCount;
    }
};