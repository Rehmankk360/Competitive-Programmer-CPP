class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
     int n = nums.size();
     long long operation = 0;
     int prev = 1e9+7;
     for(int i=n-1;i>=0;i--)
     {
        int count ;
        if(nums[i]%prev==0)  
        {
            count = nums[i]/prev;
            prev = nums[i]/count;
        }
        else if(nums[i]%prev!=0)  
        {                         
          count = (nums[i]+prev-1)/prev;
          prev = nums[i]/count;
        }
        operation += count-1;
     }
     return operation;
    }
};