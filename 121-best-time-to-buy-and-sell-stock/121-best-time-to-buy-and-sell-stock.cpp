class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxPro=0;
        int minBuy=INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            minBuy= min(minBuy, prices[i]);
            maxPro= max(maxPro, prices[i]-minBuy);
        }
     
       return maxPro; 
    }
};