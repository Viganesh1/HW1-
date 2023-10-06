#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


double dot_product (vector<double> w, vector<double> x) {
	double z = 0;
	int i;
	for (i = 0; i < w.size(); i++) {
		z = w[i] * x[i] + z;
	}

	return z;

}

int main() {
	vector <double> w{ 0.0001, 0.0001, 0.0001 };
	vector <double> x{ 124, 31.89, 20.945 };
	double z = dot_product (w,x);

	cout << "w = {0.0001, 0.0001, 0.0001}"  << endl;
	cout << "x = {124, 31.89, 20.945}" << endl;
	cout << "z = w^Tx = " << z << endl;

	return 0;

}
