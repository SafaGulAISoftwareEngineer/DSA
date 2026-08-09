class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
     // Step 1: Sort by starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // First interval
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {

            // Overlap
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            }

            // No overlap
            else {
                ans.push_back(current);
                current = intervals[i];
            }
        }

        // Add the last interval
        ans.push_back(current);

        return ans;
    }
};