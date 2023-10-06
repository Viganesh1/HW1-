#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// dot product
double dot_product (vector<double> w, vector<double> x) {
	double z = 0;
	int i;
	for (i = 0; i < w.size(); i++) {
		z = w[i] * x[i] + z;
	}

	return z;

}

int main() {
	vector <double> w{ 0.0001, 0.0001, 0.0001 }; //given values for vector w
	vector <double> x{ 124, 31.89, 20.945 };     //given values for vector x
	double z = dot_product (w,x);				 // fucntion dot product

	cout << "z = w^Tx = " << z << endl;			// output of z after dotproduct

	return 0;

}
