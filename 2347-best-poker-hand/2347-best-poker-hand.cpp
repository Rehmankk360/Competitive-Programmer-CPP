class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> s;
        unordered_map<int,int> m;
        for(int i=0;i<5;i++){
            s.insert(suits[i]);
            m[ranks[i]]++;
        }
        if(s.size()==1)
            return "Flush";
        for(auto x: m){
            if(x.second>=3)
                return "Three of a Kind";
        }
        for(auto x: m){
            if(x.second==2)
                return "Pair";
        }
        return "High Card";
    }
};