class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        if(n < 3) return 0;

        int i = 1, ans = 0;
        while(i <  n-1){

            if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]){
                int left = i - 1, right = i + 1;
            
                while(left > 0 && arr[left - 1] < arr[left]){
                    left--;
                }

                while(right < n - 1 && arr[right] > arr[right + 1]){
                    right++;
                }

                ans = max(ans, right - left + 1);

                i = right;
            }
            else i++;
        }
        return ans;
    }
};



/**

# Approaches:

1. Brute-Force Approach:

Iterates over all possible subarrays to check if they form a valid mountain.
Uses the isMountain function to validate each subarray by finding a peak and ensuring strict increasing and decreasing sequences.

Time Complexity:
Outer Loops: O(n^2) for iterating all pairs (i,j).
isMountain Function: O(n) in the worst case for checking each subarray.
Overall: O(n^3).

Space Complexity:O(1), no extra space is used aside from variables.

2. Optimized Approach (Peak Expansion)

Detects peaks and expands outward to determine mountain boundaries.
Skips elements that have already been processed as part of a mountain.

Time Complexity:
Peak Detection: O(n), each element is visited once during the main loop.
Expansion: Each element is visited at most once during left and right expansions.
Overall: O(n).

Space Complexity: O(1), no extra space is used aside from variables.

**/

