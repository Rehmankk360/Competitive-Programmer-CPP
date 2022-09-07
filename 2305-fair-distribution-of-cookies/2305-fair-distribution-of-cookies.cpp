class Solution {
public:
    void getminUNFAIRNESS(vector<int>& cookies, vector<int> children, int index, int k, int maxDist, int &globalMin){
        if(index==cookies.size()){
            globalMin = min(globalMin, maxDist);
            return;
        }
        for(int i=0; i<k; i++){
            children[i] += cookies[index];
			// Find unfairness while traversing. No need to use loop to find it at the end after getting distribution.
            getminUNFAIRNESS(cookies, children, index+1, k, max(maxDist, children[i]), globalMin);
            children[i] -= cookies[index];
			// To avoid duplicates like [33,0] and [0,33] are same so drop one.
            if(children[i]==0) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int globalMin=INT_MAX;
        vector<int> children(k);
        getminUNFAIRNESS(cookies, children, 0, k, 0, globalMin);
        return globalMin;
    }
};