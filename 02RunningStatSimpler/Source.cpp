#include <iostream>
#include <assert.h>

class Simpler {
public:
	void Push(double x) {
		count++;
		const double newMean = mean + (x - mean) / count;
		const double newSum = sum + (x - mean) * (x - newMean);
		mean = newMean;
		sum = newSum;
	}
	int Count() const {
		return count;
	}
	double Mean() const {
		return (count > 0) ? mean : 0.0;
	}
	double Variance() const {
		return ((count > 1) ? sum / (count - 1) : 0.0);
	}
	double StandardDeviation() const {
		return sqrt(Variance());
	}
private:
	int count = 0;
	double mean = 0, sum = 0;
};

void main() {
	Simpler stat;
	stat.Push(3);
	assert(stat.Mean() == 3);
	assert(stat.Variance() == 0);
	stat.Push(7);
	assert(stat.Mean() == 5);
	assert(stat.Variance() == 8);
	stat.Push(11);
	assert(stat.Mean() == 7);
	assert(stat.Variance() == 16);
	std::cout << "ok";
	std::cin.get();
}