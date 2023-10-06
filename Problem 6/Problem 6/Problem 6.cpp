#include <iostream>
using namespace std;

//function named gradient_cost
double gradient_cost(double y_predict, double y) {
	double dC = 2 * (y_predict - y);
	return dC;
}

int main() {
	double y = 1 ;  // given y value
	double y_predict = 0.504421;  // given ypredict value
	double dc = gradient_cost(y_predict, y); //gradientcost fucntion

	//output of dC
	cout << "dc = 2 * (y_predict - y) = " << dc << endl;

	return 0;



}