//sliding window problem
//T.C - O(n)
//S.C - O(n)
//Approach - take a profit_Arr[i] = prices[i]*strategy[i]
//         - max -> originalProfit - originalProfitOfWindow + ModifiedProfitOfWindiow
//         - max -> ModifiedProfitOfWindiow - originalProfitOfWindow
//for originalProfitOfWindow - use - profit_Arr
//for originalProfitOfWindow - use - prices array
class Solution {
public:
    // x = original_profit_of_window
    // y = modified_profit_of_window 
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> profit_arr;
        long long OriginalProfit=0;
        for(int i=0;i<n;i++){
            profit_arr.push_back(prices[i]*strategy[i]);
            OriginalProfit+=prices[i]*strategy[i];
        }
        long long x=0;
        long long y=0;
        int i=0;
        long long max_gain=0;
        for(int j=0;j<n;j++){
            x+=profit_arr[j];
            if(j-i+1>k/2)   y+=prices[j];

            if(j-i+1>k){
                x-=profit_arr[i];
                y-=prices[i+k/2];
                i++;
            }
            if(j-i+1==k)    max_gain=max(max_gain,y-x);
        }
        return OriginalProfit+max_gain;
    }
};
