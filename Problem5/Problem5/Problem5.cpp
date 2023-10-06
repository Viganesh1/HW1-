#include <iostream>
#include <math.h>
using namespace std;

double sigmoid(double z) {
	double delta_z = 1 / 1 + exp(-z);
	return delta_z;
}

double gradient_sigmoid(double delta_z) {
	double delta_z_der = delta_z * (1 - delta_z);
	return delta_z_der;
}

int main() {
	double z = 0.0176835;
	double delta_z = 0.504421;
	double delta_z_der = gradient_sigmoid (delta_z);

	cout << "z = " << z << endl;
	cout << "delta_z = 1/(1+e^-z) = " << delta_z << endl;
	cout << "delta_z_der = delta_z * (1 - delta_z) = " << delta_z_der << endl;


}