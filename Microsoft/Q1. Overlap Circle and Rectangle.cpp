class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xClosest = max(x1, min(xCenter, x2));
        int yClosest = max(y1, min(yCenter, y2));

        int dist = (xClosest - xCenter)*(xClosest - xCenter) + (yClosest - yCenter)*(yClosest - yCenter);

        return (dist <= radius*radius);
    }
};


/**

# Approaches to Check Circle and Rectangle Overlap

1. Brute Force Approach
Idea: Iterate over all points in the rectangle and check if each point lies inside the circle using:
(x−xcenter​)^2 + (y−ycenter)^2 ≤ radius^2
 
Time Complexity: O((x2−x1)×(y2−y1))
Space Complexity: O(1)

2. Optimized Approach
Idea: Compute the closest point on the rectangle to the circle's center. 
Check if the distance between this point and the circle's center is less than or equal to the radius:

Closest Point:
closestX=max(x1,min(xCenter,x2)),closestY=max(y1,min(yCenter,y2))
Squared Distance: (xCenter−closestX)^2 + (yCenter−closestY)^2 ≤ radius^2
 
Time Complexity: O(1)
Space Complexity: O(1)

**/
