class Solution {
public:
    int findTheWinner(int n, int k) {
        int i = 1, ans = 0;
        while(i <= n){
            ans = (ans + k) % i;
            i++;
        }

        return (ans + 1);
    }
};


/**

# Approaches to Solve the Problem

1. Brute Force Approach (Simulation with a Vector):

Idea: Simulate the elimination process using a vector to represent the circle.

Start with all 𝑛 friends in a vector.
Use modular arithmetic to calculate the index of the friend to remove.
Remove friends one by one until only one remains.

Time Complexity: O(n^2)
Each erase operation takes O(n), repeated (n−1) times.

Space Complexity: O(n) for the vector.


2. Optimal Approach (Mathematical Josephus):

Idea: Use the Josephus formula:

Winner position evolves as: winner=(winner+k)%i
Start from the base case (n=1,winner=0) and build iteratively.

Time Complexity: O(n)
Single loop.

Space Complexity: O(1)
No additional data structures.

**/
