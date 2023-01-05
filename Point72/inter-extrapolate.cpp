// Online C++ compiler to run C++ program online
#include <iostream>

double interExtrapolate(double x1, double y1, double x2, double y2, double x) {
    double y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
    return y;
}

int main() {
    double x1 = 10.0, y1 = 5.0;
    double x2 = 20.0, y2 = 10.0;
    double x = 15.0;
    
    double y = interExtrapolate(x1,y1,x2,y2,x);
    std::cout << "Estimated Value: " << y << std::endl;
    return 0;
}
