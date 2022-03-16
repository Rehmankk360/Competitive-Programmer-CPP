class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows <= 1) return s;
        vector<string> zigzag(numRows, "");
        int len = s.size();
        int state = 0, row = 0;
        for (int i = 0; i < len;)
        {
            if (state == 0) 
            {
                zigzag[row++] += s[i++];
                if (row == numRows)
                {
                    row = numRows - 2;
                    state = 1; 
                }
            } 
            else
            {
          
                if (row >= 1)
                {
                    zigzag[row--] += s[i++];
                    if (row == 0) state = 0;
                } 
                else
                {
                    row = 0;
                    state = 0;
                }
            }
        }
        string ans;
        for(auto a: zigzag) ans += a;
        return ans;
    }
};