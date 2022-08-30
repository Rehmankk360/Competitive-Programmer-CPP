class Solution {
public:
    int dp[100001][28]; 
    int fun(string& s ,int i ,  int k , int prev){ 
     if(i == s.size()) return 0; 
         if(dp[i][prev] != -1) return dp[i][prev]; 
        int a = 0  , b = 0; 
      if( prev == 27 || abs( (s[i] - 'a') - prev) <= k ){ 
         a = fun(s , i+ 1, k , (s[i] - 'a')) + 1; 
      }
        b = fun(s , i+ 1, k , prev); 
        
        return dp[i][prev] = max(a , b);
        
    }
    
    int longestIdealString(string s, int k) {
     memset(dp , -1 , sizeof(dp)); 
          return fun(s ,0 ,  k , 27); 
    }
};