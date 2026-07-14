class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int num : nums) {

            sum += num;

            int remainder = ((sum % k) + k) % k;

            if(mp.find(remainder) != mp.end())
                count += mp[remainder];

            mp[remainder]++;
        }

        return count;
    }
};