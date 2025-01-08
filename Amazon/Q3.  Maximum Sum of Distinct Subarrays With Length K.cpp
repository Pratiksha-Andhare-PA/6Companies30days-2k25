class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < k) return 0;

        unordered_map<int, int> mp;

        long long sum = 0, ans = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }

        if(mp.size() == k) ans = sum;

        int left = 0;
        for(int right = k; right < n; right++){
            sum += nums[right];
            mp[nums[right]]++;

            sum -= nums[left];
            mp[nums[left]]--;

            if(mp[nums[left]] == 0) mp.erase(nums[left]);

            if(mp.size() == k) ans = max(ans, sum);

            left++;
        }

        return ans;
    }
};



/**

# Approaches:

1. Brute-Force Approach:

Checks all subarrays of length 𝑘 and uses a frequency map to ensure the subarray has exactly 𝑘 distinct elements before calculating its sum.
Time Complexity: O(n^3)
Space Complexity: O(n)


2. Optimized Sliding Window Approach:
Uses a sliding window with two pointers and an unordered_map to maintain a window of size 𝑘 with distinct elements, 
updating the sum when the window is valid.

Time Complexity: O(n)
Space Complexity: O(k)

**/
