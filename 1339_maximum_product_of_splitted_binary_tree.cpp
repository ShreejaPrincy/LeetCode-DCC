//optimised and clean code 
//T.C : O(n)
//S.C : O(n) if we consider recursion stack space, else O(1)
class Solution {
public:
    
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum             = root->val + leftSubtreeSum + rightSubtreeSum;
        
        maxP = max(maxP, (totalSum - sum) * sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        totalSum = findTotalSum(root);
        
        
        findTotalSum(root);
        
        return maxP%M;
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//my code


class Solution {
    int mod=1e9+7;
    void sumtree(TreeNode* root,int &Tsum){
        if(root==nullptr)   return;
        Tsum+=root->val;
        sumtree(root->left,Tsum);
        sumtree(root->right,Tsum);
    }
    int solve(TreeNode* root,int Tsum,int N1sum,long long &ans){
        if(root==nullptr)   return 0;
        int x=solve(root->left,Tsum,N1sum,ans);
        int y=solve(root->right,Tsum,N1sum,ans);
        N1sum+=root->val+x+y;
        int N2sum=Tsum-N1sum;
        ans=max(ans,1LL*N1sum*N2sum);
        return N1sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long ans=INT_MIN;
        int N1sum=0,Tsum=0;
        sumtree(root,Tsum);
        solve(root,Tsum,N1sum,ans);
        return (int)(ans%mod);
    }
};



