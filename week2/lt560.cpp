class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, preSum = 0;
        for (auto& x : nums) {
            preSum += x;
            if (mp.find(preSum - k) != mp.end()) {
                count += mp[preSum - k];
            }
            mp[preSum]++;
        }
        return count;
    }
};