class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int res = 0;
    unordered_map<int, int> h;
    int l = 0;
    int r = 0;
    while (r < s.length())
    {
                        h[s[r]]++;
                     

        while(h[s[r]]>1)
        {
            h[s[l]]--;
            l++;
        }
        r++;
        res = max(res, r-l);
    }
    return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
        
    }
};


