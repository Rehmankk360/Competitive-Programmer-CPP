class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int rs = 0;
    vector<int> h(127);
    int l = 0;
    int r = 0;
    while (r < s.length())
    {
        h[s[r]]++;
        while (h[s[r]] > 1)
        {
            h[s[l]]--;
            l++;
        }
        r++;
        rs = max(rs, r - l);
    }
    return rs;
    }
};


