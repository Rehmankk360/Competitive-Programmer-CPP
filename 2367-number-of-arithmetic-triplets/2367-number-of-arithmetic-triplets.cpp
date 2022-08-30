class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        set<int> s;
        int count = 0;
        for(int i = 0 ;i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        for(auto i = s.begin(); i != s.end(); i++)
        {
            if(s.find(*i + diff) != s.end())
            {
                if(s.find(*i + diff + diff) != s.end())
                    count++;
            }
        }
        return count;
    }
};