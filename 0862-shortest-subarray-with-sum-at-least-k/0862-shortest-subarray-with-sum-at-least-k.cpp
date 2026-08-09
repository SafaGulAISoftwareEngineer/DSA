class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;

        int answer = INT_MAX;

        for (int i = 0; i <= n; i++) {

            // 1. We found a valid subarray
            while (!dq.empty() &&
                   prefix[i] - prefix[dq.front()] >= k) {

                answer = min(answer, i - dq.front());

                dq.pop_front();
            }

            // 2. Remove dominated prefix sums
            while (!dq.empty() &&
                   prefix[dq.back()] >= prefix[i]) {

                dq.pop_back();
            }

            // 3. Add current prefix index
            dq.push_back(i);
        }

        if (answer == INT_MAX)
            return -1;

        return answer;
    }
};