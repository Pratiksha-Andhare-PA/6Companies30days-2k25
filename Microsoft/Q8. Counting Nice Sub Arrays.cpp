class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> prefixCnt;
        prefixCnt[0] = 1;

        int ans = 0, oddCnt = 0;
        for(int i = 0; i < n; i++){
            oddCnt += (nums[i] % 2);

            if(oddCnt >= k){
                ans += prefixCnt[oddCnt - k];
            }
            prefixCnt[oddCnt]++;
        }

        return ans;
    }
};


/**

# Approaches:

1. Brute Force Approach:

This approach iterates through all possible subarrays and counts the odd numbers in each subarray. 
If the count of odd numbers equals 𝑘, the subarray is considered nice.

Time Complexity: O(n^2 ) due to iterating over all subarrays.
Space Complexity: O(1), as no additional data structures are used.

2. Optimal Approach:

This approach uses the sliding window technique with prefix sums. 
By maintaining a running count of odd numbers and using a hash map to track previous occurrences of specific odd counts, 
we can efficiently count the nice subarrays.

Time Complexity: O(n), as the array is processed in a single pass.
Space Complexity: O(n) due to the hash map storing the frequency of odd counts.


**/
