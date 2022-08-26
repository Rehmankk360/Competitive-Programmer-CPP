class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> ump1;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                ump1[i+j]++;
                
            }
            
            
        }
        int res=0;
        for(int k:nums3)
        {
            for(int l:nums4)
            {
                res+=ump1[-(k+l)];
            }
            
            
        }
        return res;
        
    }
};