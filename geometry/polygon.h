
#ifndef POLYGON_SRC_POLYGON_H 
#define POLYGON_SRC_POLYGON_H 

#include <vector>
#include "vector.h"
#include "shape.h"

class polygon : public shape{
private:
    std::vector<vector> _v;

public:

    polygon(std::vector<vector> v){
        _v = v;
    }

    vector center() const{
        int n = _v.size();
        double x=0,y=0;
        for(int i=0; i<n; i++){
            x += _v[i].x; y += _v[i].y;
        }
        x /= n; y /= n;
        vector res(x,y);
        return res;
    }
    
    void scale(double coefficient){
        vector c = center();
        for(int i=0; i<_v.size();i++){
            double x = _v[i].x;
            double y = _v[i].y;
            x = (x-c.x)*coefficient + c.x;
            y = (y-c.y)*coefficient + c.y;
            _v[i].x = x;
            _v[i].y = y;
        }
    }

    const std::vector<vector>& get_vertices() const{
        return _v;
    }

    int vertices_count() const{
        return _v.size();
    }
    
    double perimeter() const{
        return count_perimeter(_v);
    }

    double area() const {
        return count_area(_v);
    }

    bool congruent_to(const shape& other) const{
        return equal(perimeter(), other.perimeter());
    }
    
    void rotate(double angle){
        vector cp = center();
        for(int i=0; i<_v.size();i++){
            double x = _v[i].x;
            double y = _v[i].y;
            float s = sin(angle);
            float c = cos(angle);

            // translate point back to origin:
            x -= cp.x;
            y -= cp.y;

            // rotate point
            float xnew = x * c - y * s;
            float ynew = x * s + y * c;

            // translate point back:
            x = xnew + cp.x;
            y = ynew + cp.y;
            _v[i].x = x;
            _v[i].y = y;
        }
    }

    void translate(vector transform){
    }
    
    bool operator== (const shape& other) const{
        
        // circle c = <dynamic_casting*>other; //a
        // If (c != null)
        //   call its func
        return equal(center().x, other.center().x) && equal(center().y, other.center().y);
    }

    bool operator!= (const shape& other) const{
        return !(*this == other);
    }

    double cross_product(double x1, double y1, double x2, double y2) const{
        return (x1*y2 - x2*y1);
    }
    
    double count_area(const std::vector<vector> &vert) const{
        int n = vert.size();
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            vector v1 = vert[i];
            vector v2 = vert[(i+1)%n];
            area += cross_product(v1.x, v1.y, v2.x, v2.y);
        }
        return fabs(area)/2;
    }
    
    double count_perimeter(const std::vector<vector> &vert) const{
        int n = vert.size();
        double perimeter = 0.0;
        for (int i=0; i < n; i++) {
            double delta_x, delta_y;
            vector v1 = vert[i];
            vector v2 = vert[(i+1)%n];
            delta_x = v2.x - v1.x;
            delta_y = v2.y - v1.y;
            perimeter += sqrt(pow(delta_x, 2) + pow(delta_y, 2));
        }
        return perimeter;
    }

};

#endif