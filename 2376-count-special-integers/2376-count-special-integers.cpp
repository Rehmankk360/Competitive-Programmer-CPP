class Solution {
    int dp[11][2][1024];
    int helper(string &str, int pos, int tight, int mask){
        if(pos == str.size()){
            return mask != 0;
        }
        if(dp[pos][tight][mask] != -1){
            return dp[pos][tight][mask];
        }
        int ans = 0;
        if(tight == 1){
            for(int i=0; i<= str[pos]-'0'; i++){
                if(mask & (1<<i)) continue;
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1<<i)));
                if(i == str[pos]-'0'){
                    ans = ans + helper(str, pos+1, 1, newMask);
                }
                else{
                    ans = ans + helper(str, pos+1, 0, newMask);
                }
            }
        }
        else{
            
            for(int i=0; i<=9; i++){
                if(mask & (1<<i)) continue;
                int  newMask = (mask == 0 && i == 0 ? mask : (mask | (1<<i)));
                ans = ans + helper(str, pos+1, 0, newMask);
            }
        }
        return dp[pos][tight][mask] = ans;
    }
public:
    int countSpecialNumbers(int n) {
        string str = to_string(n);
        memset(dp, -1, sizeof(dp));
        int res = helper(str, 0, 1, 0);
        return res;
    }
};