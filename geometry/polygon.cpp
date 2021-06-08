#include <iostream>
#include <cmath>

// Code to calculate polygon methods

using std::cin;
using std::cout;
using std::endl;

double cross_product(double x1, double y1, double x2, double y2) {
  return (x1*y2 - x2*y1);
}

double count_area(const size_t n, const double * const x, const double * const y) {
  double area = 0.0;
  for (size_t i = 0; i < n; i++) {
    area += cross_product(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
  }
  return fabs(area)/2;
}

double count_perimeter(const size_t n, const double * const x, const double * const y) {
  double perimeter = 0.0;
  for (size_t i=0; i < n; i++) {
    double delta_x, delta_y;
    delta_x = (x[(i+1)%n]) - (x[i]);
    delta_y = (y[(i+1)%n]) - (y[i]);
    perimeter += sqrt(pow(delta_x, 2) + pow(delta_y, 2));
  }
  return perimeter;
}

int main() {
  size_t n;
  cin >> n;

  double *x, *y;
  x = new double[n];
  y = new double[n];

  for (size_t i = 0; i < n; i ++)
    cin >> x[i] >> y[i];

  cout << "Area: " << count_area(n, x, y) << endl;
  cout << "Perimeter: " << count_perimeter(n, x, y) << endl;

  delete[] x;
  delete[] y;

  return 0;
}
