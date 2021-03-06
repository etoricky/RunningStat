#include <iostream>
#include <assert.h>

class Welford {
public:
	void Add(double x) {
		count++;
		const double last_mean = mean;
		mean = mean + (x - mean) / count;
		sum = sum + (x - last_mean) * (x - mean);
	}
	int Count() const {
		return count;
	}
	double Mean() const {
		return mean;
	}
	double Var() const {
		return ((count > 1) ? sum / (count - 1) : 0.0);
	}
	double Std() const {
		return sqrt(Var());
	}
private:
	int count = 0;
	double mean = 0, sum = 0;
};

void main() {
	Welford object;
	object.Add(3);
	assert(object.Mean() == 3); // =AVERAGE(3)
	assert(object.Var() == 0); // =VAR.S(3)
	object.Add(7);
	assert(object.Mean() == 5); // =AVERAGE(3,7)
	assert(object.Var() == 8); // =VAR.S(3,7)
	object.Add(11);
	assert(object.Mean() == 7); // =AVERAGE(3,7,11)
	assert(object.Var() == 16); // =VAR.S(3,7,11)
	std::cout << "ok";
	std::cin.get();
}