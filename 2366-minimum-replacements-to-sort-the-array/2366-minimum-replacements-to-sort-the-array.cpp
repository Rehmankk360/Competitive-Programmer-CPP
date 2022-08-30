class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
     int n = nums.size();
     long long operation = 0;
     int prev = 1e9+7;
     for(int i=n-1;i>=0;i--)
     {
        // Here count denotes that no. of components after breaking 
        int count ;
        if(nums[i]%prev==0)  // Like 5 5 => count=1 => operation=0
        {
            count = nums[i]/prev;
            prev = nums[i]/count;
        }
        else if(nums[i]%prev!=0)  //  case 1: 5 7 => count=1 => operation=0
        {                         //  case 2: 9 5 => count=2 => operation=1
          count = (nums[i]+prev-1)/prev;
          prev = nums[i]/count;
        }
        operation += count-1; // for 'count' components we need minimum count-1 operation
     }
     return operation;
    }
};