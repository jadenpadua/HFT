#include <iostream>
#include <cmath>

using namespace std;

float cost_function(float x) {
    return (x*x) - 4*x + 4;
}

float cost_derivative(float x) {
    return 2*x - 4;
}

int main() {
    float alpha = 0.01, x = 0;
    int epochs = 1000;
    
    for(int i = 0; i < epochs; ++i) {
        x = x - alpha * cost_derivative(x);
    }
    
    cout << "Minimum found at x = " << x << endl;
    
    return 0;
}
