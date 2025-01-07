class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> ans;

        int n = s.length();
        for(int i = 0; i <= n-10; i++){
            string substr = s.substr(i, 10);

            if(seen.find(substr) != seen.end()){
                ans.insert(substr);
            }

            else{
                seen.insert(substr);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};

/**

# Sliding Window Approach:
This approach uses a sliding window of size 10.

Sliding Window: Traverse the string with a sliding window of length 10, and extract each 10-character-long substring.

Hashing: Use two hash sets:
1. seen: Tracks substrings that have been encountered.
2. ans: Stores repeated substrings that appear more than once.

For each substring:
If it has been seen before, add it to the ans set.
Otherwise, add it to the seen set.

Convert the result set ans to a vector and return it.
Time Complexity: O(n), where 𝑛 is the length of the string,
because we only scan the string once and perform constant-time operations with hash sets.

Space Complexity: O(n), due to the storage of substrings in hash sets.

**/
