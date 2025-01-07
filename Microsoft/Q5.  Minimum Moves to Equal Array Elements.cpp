class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int median = nums[n/2];

        long long ans = 0;
        for(auto num : nums){
            ans += abs(num - median);
        }

        return ans;
    }
};

/**

# Approaches:

1. Brute Force Approach

Idea: Test every possible target value between the minimum and maximum array values. 
For each target, calculate the total moves needed and return the minimum.

Time Complexity: O(n×range), where range = max(nums) - min(nums).
Space Complexity: O(1).
Limitation: Inefficient for large input ranges.(Got TLE)

2. Optimal Approach (Median)

Idea: The median minimizes the total moves when aligning all elements to a common value. 
Sort the array, pick the median, and compute the total moves.

Time Complexity: O(nlogn) due to sorting.
Space Complexity: O(1) if sorting in-place.
Advantage: Fast and efficient, suitable for large inputs.

**/
