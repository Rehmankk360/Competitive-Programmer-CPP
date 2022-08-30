class Solution {
public:
  
    char shift(char a, int n){
        int i = a - 'a';
        i = (i+n)%26;
        
        //negative case
        if(i<0)
            i = i+26;
        
        return 'a' + i;
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> presum(n+1,0);
        
        for(auto x: shifts){
            
            if(x[2]==0){
                presum[x[0]]--;;
                presum[x[1]+1]++;
            }
            else{
                presum[x[0]]++;;
                presum[x[1]+1]--;
            }            
        }
        
        for(int i = 1; i<presum.size();i++)
            presum[i]+=presum[i-1];        
        
        string ans = "";
        for(int i =0; i<n; i++)
            ans+= shift(s[i],presum[i]);
        
        return ans;
        
        
    }
};