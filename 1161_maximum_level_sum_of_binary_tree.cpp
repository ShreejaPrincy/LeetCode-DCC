//Approach-1 (Using BFS - T.C : O(n))
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resultLevel = 0;
        int currLevel = 1;
        
        queue<TreeNode*> que;
        que.push(root);
        
        
        while(!que.empty()) {

            int n = que.size();
            
            int sum = 0;
            
            while(n--) {
                
                TreeNode* node = que.front();
                que.pop();
                
                sum += node->val;
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
            
            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = currLevel;
            }
            currLevel++;
        }
        
        return resultLevel;
        
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Approach-2 (Using DFS - T.C : O(n))
class Solution {
public:
    
    map<int, int> mp;
    
    void DFS(TreeNode* root, int currLevel) {
        
        if(!root)
            return;
        
        mp[currLevel] += root->val;
        
        DFS(root->left, currLevel+1);
        DFS(root->right, currLevel+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        
        DFS(root, 1);
        
        int maxSum = INT_MIN;
        int result = 0;
        
        for(auto &it : mp) {
            
            int level = it.first;
            int sum   = it.second;
            
            if(sum > maxSum) {
                maxSum = sum;
                result = level;
            }
            
        }
        
        return result;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//my code using vector

class Solution {
public:
    void solve(TreeNode* root,vector<int> &sum,int level){
        if(root==nullptr)   return ;
        
        if(sum[level]==INT_MIN) sum[level]=0;

        sum[level]+=root->val;
        solve(root->left,sum,level+1);
        solve(root->right,sum,level+1);

    }
    int maxLevelSum(TreeNode* root) {
        int level=1;
        vector<int>sum(10000+1,INT_MIN);         //*dont use 10^4 instead use 10000
        solve(root,sum,level);
        int summ=INT_MIN;
        int ans;

        for(int i=0;i<sum.size();i++){          //for(int i:sum) -> i is not index,i is value of sum
            if(summ<sum[i]){              //stuck: used (summ<=sum[i]) but it should be summ<sum[i]
                summ=sum[i];
                ans =i;
            }
        }
        return ans;
    }
};


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Improved Version (Clean & Safe) of my code
  
  class Solution {
public:
    void solve(TreeNode* root, vector<int>& sum, int level) {
        if (!root) return;

        if (level == sum.size())                    //*
            sum.push_back(0);

        sum[level] += root->val;

        solve(root->left, sum, level + 1);
        solve(root->right, sum, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        solve(root, sum, 0);

        int maxSum = INT_MIN;
        int ans = 0;

        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > maxSum) {
                maxSum = sum[i];
                ans = i;
            }
        }
        return ans + 1; // convert to 1-based level
    }
};
