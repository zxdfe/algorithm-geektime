class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int degree = 0;
        // 最大度
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            degree = max(degree, mp[nums[i]]);
        }
        mp.erase(mp.begin(), mp.end());

        int ans = nums.size();
        int left = 0, right = 0;
        while(right < nums.size()) {
            mp[nums[right]] ++;
            // 频数达到要求后，移动左边界
            while(mp[nums[right]] == degree) {
                ans = min(ans, right - left + 1);
                mp[nums[left ++]] --;
            }
            right ++;
        }
        return ans;
    }
};