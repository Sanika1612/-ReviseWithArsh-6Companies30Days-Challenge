//brute force
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                long long lhs=radius*radius;
                long long rhs= (xCenter-i)*(xCenter-i)+(yCenter-j)*(yCenter-j);
                
                if(lhs>=rhs) {
                    cout<<i<<" "<<j<<" "<<lhs<<" "<<rhs<<endl;

                    return true;
                }
            }
        }
        return false;
    }
};

//best solution

// OJ: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Move the center of the circle to the coordinate origin (0, 0), then this problem becomes "is there a point (x, y) (x1 <= x <= x2, y1 <= y <= y2) satisfying x^2 + y^2 <= r^2".

// So just compute minimum values of x^2 and y^2, then compare the sum with r^2..
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
       //Transform (x_center,y_center) to (0,0)
        x1 -= x_center; x2 -= x_center;
        y1 -= y_center; y2 -= y_center;
        //Check if x1 and x2 are both in same side of y axis(left and right side)
// If not then min possible point lies on y-axis.
        int minX = x1 * x2 > 0 ? min(x1*x1, x2*x2) : 0, minY = y1 * y2 > 0 ? 
        min(y1*y1, y2*y2) :   0;
        return minY + minX <= radius * radius;
    }
};

