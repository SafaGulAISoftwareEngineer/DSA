class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    
        int currentSum = nums[0];
        int maximumSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            currentSum = max(nums[i], currentSum + nums[i]);

            maximumSum = max(maximumSum, currentSum);
        }

        return maximumSum;
    }
};