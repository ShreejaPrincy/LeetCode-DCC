// Day 1 of DCC
// 2110. Number of Smooth Descent Periods.cpp

//my code

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long cnt=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1)    cnt++;
            else {
                ans+=cnt * (cnt + 1) / 2;
                cnt=1;
            } 
        }
        ans+=1LL*cnt * (cnt + 1) / 2;
        return ans;
    }
};

//another and easy approach

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=1;
        long long cnt=1;
        for(int i=1;i<prices.size();i++){

            if(prices[i-1]-prices[i]==1)    cnt++;
            else    cnt=1;

            ans+=cnt;
        }
        return ans;
    }
};
