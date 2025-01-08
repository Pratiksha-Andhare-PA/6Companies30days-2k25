class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int right = n - 1;
        while(right > 0 && nums[right - 1] < nums[right]) right--;

        if(right == 0){
            return (long long)n * (n + 1) / 2;
        }

        long long ans = n - right + 1;
        for(int left = 0; left == 0 || nums[left - 1] < nums[left]; left++){
            while(right < n && nums[left] >= nums[right]){
                right++;
            }
            ans += (n - right + 1);
        }
        return ans;
    }
};

/**

# Approaches:

Approach 1: Brute Force
Explanation: This approach generates all possible subarrays by removing elements 
in the range [i,j] and checks if the resulting array is strictly increasing. 
It uses nested loops to handle subarray generation and a helper function to verify strict monotonicity.

Time Complexity: O(n^3), as it involves three nested loops and a linear check for each subarray.
Space Complexity: O(n), for the temporary array used to store the reduced subarray.

Approach 2: Optimized Two Pointers
Explanation: This approach uses the two-pointer technique. 
It calculates the number of valid subarrays directly by maintaining a right pointer and 
incrementally counting valid subarrays as the left pointer progresses. 
This avoids generating subarrays explicitly.

Time Complexity: O(n), as each pointer traverses the array at most once.
Space Complexity: O(1), as no extra data structures are used.

**/
