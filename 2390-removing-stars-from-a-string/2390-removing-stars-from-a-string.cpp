class Solution {
public:
    string removeStars(string s) {
        string ans = "" ;
        for(auto &x : s){
            ans.push_back(x) ;
            if(ans.back() == '*'){
                ans.pop_back() ;
                if(ans.size()) ans.pop_back() ;
            }
        }
        return ans ;
    }
};