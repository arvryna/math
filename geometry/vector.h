#ifndef VECTOR_SRC_VECTOR_H 
#define VECTOR_SRC_VECTOR_H 

#include<cmath>

class vector{
    public:
    double x;
    double y;
    
    vector (){
        x = 0;
        y = 0;
    }

    vector (double first, double second){
        x = first;
        y = second;
    }

    double length() const{

        return sqrt(x*x + y*y);
    }
    
    vector& operator+= (const vector& other){
        x += other.x;
        y += other.y;
        return *this;
    }
    
    vector& operator-= (const vector& other){
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vector& operator*= (const double& other){
        x *= other;
        y *= other;
        return *this;
    }
    
    vector& operator/= (const double& other){
        x /= other;
        y /= other;
        return *this;
    }

    vector operator+ () const {
        return *this;
    }

    vector operator- () const {
        vector cpy(*this);
        cpy.x = -cpy.x;
        cpy.y = -cpy.y;
        return cpy;
    }
};

vector operator+ (const vector& first, const vector& second) {
    vector cpy(first);
    cpy.x += second.x;
    cpy.y += second.y;
    return cpy;
}

vector operator- (const vector& first, const vector& second) {
    vector cpy(first);
    cpy.x -= second.x;
    cpy.y -= second.y;
    return cpy;
}

vector operator* (const vector& v, const double& val) {
    vector cpy(v);
    cpy.x *= val;
    cpy.y *= val;
    return cpy;
}

vector operator* (const double& val, const vector& v) {
    vector cpy(v);
    cpy.x *= val;
    cpy.y *= val;
    return cpy;
}

vector operator/ (const vector& v, const double& val) {
    vector cpy(v);
    cpy.x /= val;
    cpy.y /= val;
    return cpy;
}

const double EPS = 1e-6;

bool equal(double a, double b) {
    return std::fabs(a - b) < EPS;
}

bool operator== (const vector& first, const vector& second) {
    return (equal(first.x, second.x) && equal(first.y, second.y));
}

bool operator!= (const vector& first, const vector& second) {
    return !(first==second);
}

double dot_product (const vector& lhs, const vector& rhs){
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) ;
}

double cross_product (const vector& lhs, const vector& rhs){
    return (lhs.x * rhs.y) - (lhs.y * rhs.x);
}

bool collinear (const vector& lhs, const vector& rhs){
    double res =  (lhs.x * rhs.y) - (lhs.y * rhs.x);
    return (int(res * 10000) == 0);
}


#endif