class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        vector<int> v(2, 0);
        
        for(auto it: m){
            v[0] = v[0] + it.second/2;
            v[1] = v[1] + it.second%2;
        }
        
        return v;
    }
};