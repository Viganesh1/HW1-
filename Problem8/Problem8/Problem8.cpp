#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//function sigmoid
double sigmoid(double x) { 
    if (x >= 0) {
        return 1.0 / (1.0 + exp(-x));
    }
    else {
        double exp_x = exp(x);
        return exp_x / (1.0 + exp_x);
    }
}
//function gradient_weights 
vector<double> gradient_weights( vector<double>& w,vector<double>& x, double y) {
    vector<double> dw(w.size(), 0.0);
    double wx = 0.0;
    for (int i = 0; i < w.size(); i++) {
        wx += w[i] * x[i];
    }

    double predicted_y = sigmoid(wx);

    for (int i = 0; i < w.size(); i++) {
        dw[i] = (predicted_y - y) * predicted_y * (1.0 - predicted_y) * x[i];
    }

    return dw;
}
// function update weights
void update_weights(vector<double>& w, const vector<double>& dw, double a) {
    for (int i = 0; i < w.size(); i++) {
        w[i] -= a * dw[i];
    }
}

int main() {
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    double alpha = 0.001;
    int iterations = 1000;

    vector<vector<double>>data ={
         {124, 31.89, 20.945, 1},    // M_346Master
        {74, 51.08, 9.170, 0},      // AT_402B
        {103, 34.46, 8.300, 1},     // MB_326
        {77, 52.00, 9.3400, 0},     // AT_502B
        {104, 35.63, 13.000, 1},    // MB_339
        {92, 56.00, 12.500, 0},     // AT_602
        {130, 31.29, 17.637, 1},    // Aero_L159
        {73, 52.00, 9.600, 0}       // AT_504
    };
    // for loop showing iterations
    for (int iteration = 0; iteration < iterations; ++iteration) {
        vector<double> dw_sum(w.size(), 0.0);

        for (const vector<double>& data_point : data) {
            vector<double> x = { data_point[0], data_point[1], data_point[2] };
            double y = data_point[3];
            vector<double> delta = gradient_weights(w, x, y);

            for (int i = 0; i < w.size(); i++) {
                dw_sum[i] += delta[i];
            }
        }

        update_weights(w, dw_sum, alpha);
    }
    // output of the updated w which is in between -1 and 1
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
