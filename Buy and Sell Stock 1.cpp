class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int sellPrice = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
            }else{
                sellPrice = max(sellPrice,prices[i]-buyPrice);
            }
        }
        return sellPrice;
    }
};