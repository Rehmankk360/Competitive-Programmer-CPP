class Solution {
public:
    #define ll long long
vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& rmQueries) {
	int n = nums.size();
	vector<ll> dp(n+1);
	ll acc = 0;
	for(int i = 0; i < n; i++) 
		dp[i+1] = acc += nums[i];

	vector<ll> res;
	map<int,int> ran;
	priority_queue<array<ll,3>> pq;
	pq.push({dp.back(), 0, n-1});
	ran[0] = n-1;
	for(int i = 0; i < n; i++) {
		auto it = --ran.upper_bound(rmQueries[i]);

		if(rmQueries[i]+1 < n && ran.find(rmQueries[i]+1) == ran.end()) {
			ran[rmQueries[i]+1] = it->second;
			pq.push({dp[it->second+1] - dp[rmQueries[i]+1], rmQueries[i]+1, it->second});                
		}

		if(rmQueries[i] == it->first)
			ran.erase(rmQueries[i]);
		else {
			it->second = rmQueries[i]-1;
			pq.push({dp[it->second+1] - dp[it->first], it->first, it->second});             
		}

		while(!pq.empty() && (ran.find(pq.top()[1]) == ran.end() || pq.top()[2] != ran[pq.top()[1]]))
			pq.pop();

		if(pq.empty())
			res.push_back(0);
		else
			res.push_back(pq.top()[0]);

	}

	return res;
}
};