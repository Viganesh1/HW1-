#include <iostream>
using namespace std;

double roll_rate(double Lp, double p, double L_delta, double delta) {
    double p_dot = Lp * p + L_delta * delta;
    return p_dot;
}

double roll_rate1(double p, double p_dot, double delta_t) {
    double p_t = p + p_dot * delta_t;
    return p_t;
}

int main() {
    double Lp = 0.25;
    double L_delta = 0.5;
    double p = 1;
    double delta_t = 0.01; 
    double total_time = 5.0;
    double delta;
    double t;
   
    for (t = 0; t <= total_time; t += delta_t) {
        if (t >= 0) {
            delta = 1.0;
        }
        else if (t <= 2) {
            delta = 1;
        }
        else if (t>2) {
            delta =  0;
        }

        double p_dot = roll_rate(Lp, p, L_delta, delta);
      double p_t = roll_rate1(p, p_dot, delta_t);
      p = p_t;
        cout << "At time = " << t << "sec" << ";  Roll Rate = " << p << "rad/sec" << endl;
    }

    return 0;
}