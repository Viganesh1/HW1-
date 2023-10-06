#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double gradient_weights(double delta, vector<double>& w, const vector<double>& x, double y) {
    vector<double> dw(w.size(), 0.0);
    for (int i = 0; i < w.size(); i++) {
        dw[i] = (2 * delta * (w[i] * x[i]) - y) * (delta * (w[i] * x[i]) * (1 - delta * (w[i] * x[i])) * x[i]);
    }
    return dw[0];
}

void update_weights(vector<double>& w, const vector<double>& dw, double a) {
    for (int i = 0; i < w.size(); i++) {
        w[i] -= w[i]- a * dw[i];
    }
}

int main() {
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    vector<double> x = { 124, 31.89, 20.945 };
    double a = 0.001;
    vector<double> dw = { -30.7235, -7.90136, -5.1855 };
    int y = 1;
    double delta;
    update_weights(w, dw, a);
    gradient_weights(delta, w, x, y);
    

    vector <double> M_346Master = { 124, 31.89, 20.945 };
    vector <double > AT_402B = { 74, 51.08, 9.170 };
    vector <double > MB_326 = { 103, 34.46, 8.300 };
    vector <double > AT_502B = { 77, 52.00, 9.3400 };
    vector <double > MB_339 = { 104, 35.63, 13.000 };
    vector <double > AT_602 = { 92, 56.00, 12.500 };
    vector <double > Aero_L159 = { 130, 31.29, 17.637 };
    vector < double > AT_504 = { 73, 52.00, 9.600 };

        


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