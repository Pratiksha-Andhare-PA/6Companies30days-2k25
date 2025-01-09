class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            columnNumber--;

            ans = ch('A' + columnNumber%26) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};

/**

# Complexity Analysis:

Time Complexity: O(log n), where n is the columnNumber.
Space Complexity: O(1) for auxiliary space.

**/
