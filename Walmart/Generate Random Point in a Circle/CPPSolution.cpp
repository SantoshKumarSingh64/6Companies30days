class Solution {
public:
    double x;
    double y;
    double r;
    
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    vector<double> randPoint() {
        
        double rad = (double)rand() / RAND_MAX;
        rad = sqrt(rad) * r; 
        //KEY POINT: IF WE DO NOT TAKE THE SQUARE ROOT, WE WILL HAVE MANY POINTS CLOSE TO THE CENTRE THAN FAR AWAY.
        
        double teta = (double)rand() / RAND_MAX;
        teta *= 360.0;
        
        return {x+rad*cos(teta),y+rad*sin(teta)}; //x = rcosθ, y = rsinθ
    }
};
