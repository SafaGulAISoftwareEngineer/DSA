class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
    int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        int maxSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            maxEndingHere = max(nums[i],
                                maxEndingHere + nums[i]);

            minEndingHere = min(nums[i],
                                minEndingHere + nums[i]);

            maxSum = max(maxSum, maxEndingHere);

            minSum = min(minSum, minEndingHere);
        }

        return max(abs(maxSum), abs(minSum));
    }
};