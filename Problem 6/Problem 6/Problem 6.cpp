#include <iostream>
using namespace std;


double gradient_cost(double y_predict, double y) {
	double dC = 2 * (y_predict - y);
	return dC;
}
int main() {
	double y = 1 ;
	double y_predict = 0.504421;
	double dc = gradient_cost(y_predict, y);

	cout << "y = " << y << endl;
	cout << "y_predict = " << y_predict << endl;
	cout << "dc = 2 * (y_predict - y) = " << dc << endl;

	return 0;



}