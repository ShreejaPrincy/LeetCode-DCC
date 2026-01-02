//This solution works due to an implicit use of the Pigeonhole Principle 
//— with one element appearing N times in an array of size 2N, 
//at least two occurrences must appear within a window of three consecutive indices.


//Since one element appears N times in an array of size 2N, it’s impossible for it to remain far apart.
//This means the repeated element must appear at least twice within any 3 consecutive positions.

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1]||nums[i]==nums[i+2])  return nums[i];
        }
        return nums.back();
    }
};
