class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
         map<int,int>mp;    //value -->sum of that all values weight
    
        for(int i=0;i<arr1.size();i++)
        {
           vector<int>temp=arr1[i];
           int val=temp[0];
           int wt=temp[1];

           mp[val]=mp[val]+wt;
        }
        for(int i=0;i<arr2.size();i++)
        {
           vector<int>temp=arr2[i];
           int val=temp[0];
           int wt=temp[1];

           mp[val]=mp[val]+wt;
        }
        vector<vector<int>>ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back({it->first,it->second});
        }
        return ans;
    }
};