#include <iostream>
using namespace std;

// Function to calculate pdot
double roll_rate(double Lp, double p, double L_delta, double delta) {
    double p_dot = Lp * p + L_delta * delta;
    return p_dot;
}

// Function to update the roll (p)
double roll_rate1(double p, double p_dot, double delta_t) {
    double p_t = p + p_dot * delta_t;
    return p_t;
}

int main() {
    double Lp = 0.25;             // roll damping coefficient, picked 0.25
    double L_delta = 0.5;         // aileron deflection angle, picked 0.5
    double p = 1;                 // initial roll rate, given as 1
    double delta_t = 0.01;        // Time step, set to 0.01
    double total_time = 5.0;      // total time of 5 seconds
    double delta;                 // aileron deflection angle
    double t = 0;                 // current time
    double K = 3;                  // constant gain

  
    for (t = 0; t <= total_time; t += delta_t) {
        // The value of delta based on time
        if (t >= 0) {
            delta = 1.0;
        }
        else if (t <= 2) {
            delta = 1;
        }
        else {
            delta = 0;
        }

        // Calculate the roll rate (p_dot) using the given values including k
        double p_dot = roll_rate(Lp, p, L_delta, delta);
        delta = -K * p;
        p_dot = roll_rate(Lp, p, L_delta, delta);

        p = roll_rate1(p, p_dot, delta_t);

        // out put the result for roll rate for each timestep
        cout << "At time = " << t << "sec" << ";  Roll Rate = " << p << "rad/sec" << endl;
    }

    return 0;
}