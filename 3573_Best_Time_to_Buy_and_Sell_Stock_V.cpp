//Approach-1 (Recursion + Memoization)
//T.C : O(n * k)
//S.C : O(n * k)
class Solution {
public:
    long long solve(vector<int>& prices, int k,vector<vector<vector<long long>>>&dp,int i,int b){
        if(i==prices.size()){
            if(b==0)    return 0;
            return INT_MIN;
        }
        if(dp[i][k][b]!=INT_MIN)  return dp[i][k][b];
        long long take=0;
        long long skip=0;
        
        if(b==0&&k>0){
        long long t1=-prices[i]+solve(prices,k,dp,i+1,1);
        long long t2=prices[i]+solve(prices,k,dp,i+1,2);
        take=max(t1,t2);
        }
        else if(b==1&&k>0){
        take=prices[i]+solve(prices,k-1,dp,i+1,0);
        }
        else if(b==2&&k>0){   
        take=-prices[i]+solve(prices,k-1,dp,i+1,0);
        }
        
        skip=solve(prices,k,dp,i+1,b);
        return dp[i][k][b]=max(take,skip);
    }
    long long maximumProfit(vector<int>& prices, int k) {

    vector<vector<vector<long long>>> dp(
        prices.size()+1,
        vector<vector<long long>>(
            k+1,
            vector<long long>(3, INT_MIN)
        )
    );

        int i=0;
        int b=0;
        return solve(prices,k,dp,i,b);
    }
};
