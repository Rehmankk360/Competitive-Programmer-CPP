class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> ret;
		int num = words.size(), lenWord = words[0].size();
		int len = s.size() - num * lenWord + 1;
		for (int i = 0; i < len; ++i)
		{
			int m = 0, n = num, k = i;
			while (m < n)
			{
				if (words[m][0] == s[k] && s.substr(k, lenWord) == words[m])
				{
					std::swap(words[m], words[--n]);
					k += lenWord; m = -1;
				}
				++m;
				if (0 == n) ret.push_back(i);
			}
		}
		return ret;
	}
};