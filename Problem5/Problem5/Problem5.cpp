#include <iostream>
#include <math.h>
using namespace std;

//sigmoid function
double sigmoid(double z) {
	double delta_z = 1 / 1 + exp(-z);
	return delta_z;
}
//gradient sigmoid function
double gradient_sigmoid(double delta_z) {
	double delta_z_der = delta_z * (1 - delta_z);
	return delta_z_der;
}

int main() {
	double z = 0.0176835;   //z value 
	double delta_z = 0.504421; //delta z value
	double delta_z_der = gradient_sigmoid (delta_z); // gradient_sigmoid function

	//output of gradient sigmoid
	cout << "delta_z_der = delta_z * (1 - delta_z) = " << delta_z_der << endl;


}