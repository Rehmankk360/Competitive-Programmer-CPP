class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = size(nums), m = size(nums[0]);
        vector<int> ans, v(n);
        ans.reserve(size(queries));
        iota(begin(v), end(v), 0);
        for (auto& q: queries) {
            int &k = q[0], &trim = q[1];
            nth_element(begin(v), begin(v)+k-1, end(v), [&] (int i, int j) {
                string_view a = nums[i], b = nums[j];
                auto trim_a = a.substr(m-trim, trim), trim_b = b.substr(m-trim, trim);
                return trim_a < trim_b || (trim_a == trim_b && i < j); 
            });
            ans.push_back(v[k-1]);
        }
        return ans;
    }
};