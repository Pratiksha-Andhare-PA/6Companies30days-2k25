class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end()){ // encountered first occurrence
                mp[s[i]] = i;
            }
            else mp[s[i]] = -1;
        }

        for(auto ch : s){
            if(mp[ch] != -1) return mp[ch];
        }
        return -1;
    }
};

/**

# Approaches:

1. Brute Force Approach (Nested Loops):
For each character, check against all others to find if it's unique.

Time Complexity: O(n^2) (Two nested loops).
Space Complexity: O(1) (No extra space).

2. Frequency Array Approach:
Use a fixed-size array to count the frequency of each character, 
then check for the first character with a frequency of 1.

Time Complexity: O(n) (Single pass for counting, another for checking).
Space Complexity: O(1) (Fixed array of size 26).

3. Index Map Approach:
Use a hash map to track the first index of each character, marking duplicates as -1. 
Return the smallest valid index.

Time Complexity: O(n) (One pass for populating, another for checking).
Space Complexity: O(1) (Constant space for 26 letters).


**/
