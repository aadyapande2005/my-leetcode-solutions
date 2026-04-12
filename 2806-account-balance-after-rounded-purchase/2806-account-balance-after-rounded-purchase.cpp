class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        float dec = (float)purchaseAmount/10;
        int quo = purchaseAmount/10;
        float diff = dec - quo;

        // cout<<dec<<" "<<quo<<" "<<diff<<endl;

        if(diff >= 0.5) return 100 - (quo+1)*10;
        else return 100 - quo*10;
    }
};