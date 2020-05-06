#include <iostream>
#include <assert.h>

class Welford {
public:
	void add(double x) {
		n++;
		const double new_mean = m + (x - m) / n;
		const double new_sum = s + (x - m) * (x - new_mean);
		m = new_mean;
		s = new_sum;
	}
	int count() const {
		return n;
	}
	double mean() const {
		return (n > 0) ? m : 0.0;
	}
	double var() const {
		return ((n > 1) ? s / (n - 1) : 0.0);
	}
	double std() const {
		return sqrt(var());
	}
private:
	int n = 0;
	double m = 0, s = 0;
};

void main() {
	Welford object;
	object.add(3);
	assert(object.mean() == 3); // =AVERAGE(3)
	assert(object.var() == 0); // =VAR.S(3)
	object.add(7);
	assert(object.mean() == 5); // =AVERAGE(3,7)
	assert(object.var() == 8); // =VAR.S(3,7)
	object.add(11);
	assert(object.mean() == 7); // =AVERAGE(3,7,11)
	assert(object.var() == 16); // =VAR.S(3,7,11)
	std::cout << "ok";
	std::cin.get();
}