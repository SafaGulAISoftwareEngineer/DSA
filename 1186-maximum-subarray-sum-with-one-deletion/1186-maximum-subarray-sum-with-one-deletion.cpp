class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int keep = arr[0];
        int deleteOne = 0;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int oldKeep = keep;

            keep = max(arr[i], keep + arr[i]);

            deleteOne = max(oldKeep,
                            deleteOne + arr[i]);

            ans = max(ans, max(keep, deleteOne));
        }

        return ans;  
    }
};