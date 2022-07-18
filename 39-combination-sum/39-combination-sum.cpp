class Solution {
   
    
public:
  
        vector<vector<int>> ans;
    int n;
    void sum(int i, vector<int>& cand, vector<int>& comb, int tar){
        if(i>=n || tar<0) return;
        if(tar==0) { ans.push_back(comb); return; }
        sum(i+1,cand,comb,tar);
        comb.push_back(cand[i]);
        sum(i,cand,comb,tar-cand[i]);
        comb.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int> comb;
        sum(0,candidates,comb,target);
        return ans;
    }
};