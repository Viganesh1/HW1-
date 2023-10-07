#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//function gradient weights
double gradient_weights(double delta, vector<double>& w, const vector<double>& x, double y) {
    vector<double> dw(w.size(), 0.0);  
    for (int i = 0; i < w.size(); i++) {
        dw[i] = (2 * delta * (w[i] * x[i]) - y) * (delta * (w[i] * x[i]) * (1 - delta * (w[i] * x[i])) * x[i]);
    }
    return dw[0]; 
}
//function update weights
void update_weights(vector<double>& w, const vector<double>& dw, double a) {
    for (int i = 0; i < w.size(); i++) {
        w[i] -= a * dw[i];  
    }
}

int main() {
    vector<double> w = {0.0001, 0.0001, 0.0001};
    vector<double> x = {124, 31.89, 20.945};
    double a = 0.001;
    vector<double> dw = {-30.7235, -7.90136, -5.1855};
    int y = 1;
    update_weights(w, dw, a);
    
    // output of w
    cout << "w = ";
    cout << "{ ";
    for (int i = 0; i < w.size(); i++) {
        cout << w[i];
        if (i < w.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    return 0;
}
