class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        long long int n=grades.size();
        int l=1,r=n,ans=0;
        while(l<=r){
            long long int m=l+(r-l)/2;
            long long int group=m*(m+1)/2;
            if(group<=n){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};