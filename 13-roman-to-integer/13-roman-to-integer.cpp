class Solution {
public:
 int romanToInt(string s) {
        map<char,int> mp; 
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0; 
        int n = s.length();
        int i=n;
        while(i>=0){
            if(s[i] == 'V' || s[i] =='X') 
				mp['I'] = -1;
            if(s[i] == 'L' || s[i] =='C')
				mp['X'] = -10;
            if(s[i] == 'D' || s[i] =='M')
				mp['C'] = -100;
            ans+=mp[s[i]];
            i--;   
        }
        return ans; 
    }


};