class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;
        
        for(int i = 0; i < n; i++){
            
            // Remove indices out of current window
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }
            
            // Remove indices of elements smaller than or equal to the current element
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            
            // Add the current element's index
            dq.push_back(i);
            
            // Add the maximum of the current window to the result
            if(i >= k - 1){
                ans.push_back(arr[dq.front()]);
            }
        }
        
        return ans;
    }
};


/**

# Approaches:

1. Brute Force Approach:

Iterate through all possible subarrays of size 𝑘, 
calculate the maximum for each subarray, and store the results.

Time Complexity: O(n⋅k), where 𝑛 is the size of the array.
Space Complexity: O(1), as no extra data structures are used (excluding the result vector).

Inefficient for large arrays due to nested loops.

2. Optimal Approach (Using Deque):

Use a deque to maintain indices of useful elements for each window, 
ensuring maximum is always at the front. 
Slide the window while updating the deque efficiently.

Time Complexity: O(n), as each element is processed at most twice (added and removed from the deque).
Space Complexity: O(k), for the deque to store indices.


**/
