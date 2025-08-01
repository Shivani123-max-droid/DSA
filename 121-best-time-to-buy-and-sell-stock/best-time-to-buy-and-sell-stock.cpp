class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,BestBuy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>BestBuy){
                maxProfit=max(maxProfit, prices[i]-BestBuy);
            }
            BestBuy=min(BestBuy,prices[i]);
        }
        return maxProfit;
    }
};