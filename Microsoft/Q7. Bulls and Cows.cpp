class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secretMp;
        unordered_map<char, int> guessMp;

        int n = secret.size();
        int bulls = 0, cows = 0;

        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bulls++;

            else{
                secretMp[secret[i]]++;
                guessMp[guess[i]]++;
            }
        }

        for(auto x : secretMp){
            cows += min(secretMp[x.first], guessMp[x.first]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};


/**

# Approaches:

1. Brute Force Approach:

This approach identifies bulls by comparing digits at corresponding positions in secret and guess. 
For cows, unmatched digits in guess are compared with unmatched digits in secret.

Time Complexity: O(n^2) (nested comparisons for unmatched digits).
Space Complexity: O(n) (tracking unmatched indices).

2. Optimal Approach:

Uses two maps: one to track frequencies of unmatched char of secret, 
and another to track frequencies of unmatched char of guess.

Time Complexity: O(n) (single-pass processing).
Space Complexity: O(1) (fixed-size frequency array).
The optimal approach is more efficient for larger inputs due to linear time complexity and constant space usage.


**/
