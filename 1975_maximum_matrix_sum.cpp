//my code(doitagain)
//Time: O(n²)
//Space: O(1)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        int negative=0;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0)     negative++;
                sum+=abs(matrix[i][j]);
                mini=min(abs(matrix[i][j]),mini);
            }
        }
        if(negative%2==0)   return sum;
        return sum-2*mini;
    }
};
