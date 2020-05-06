#include <iostream>
#include <assert.h>

class Covariance {
public:
	void Add(double x, double y) {
		count++;
		const double new_meanx = meanx + (x - meanx) / count;
		const double new_meany = meany + (y - meany) / count;
		const double new_sum = sum + (x - meanx) * (y - new_meany);
		meanx = new_meanx;
		meany = new_meany;
		sum = new_sum;
	}
	int Count() const {
		return count;
	}
	double MeanX() const {
		return (count > 0) ? meanx : 0.0;
	}
	double MeanY() const {
		return (count > 0) ? meany : 0.0;
	}
	double Var() const {
		return ((count > 1) ? sum / (count - 1) : 0.0);
	}
	double Std() const {
		return sqrt(Var());
	}
private:
	int count = 0;
	double meanx = 0, meany = 0, sum = 0;
};

void main() {
	{
		Covariance object;
		object.Add(3, 3);
		assert(object.MeanX() == 3); // =AVERAGE(3)
		assert(object.MeanY() == 3); // =AVERAGE(3)
		assert(object.Var() == 0); // =COVARIANCE.S({3},{3})
		object.Add(7, 7);
		assert(object.MeanX() == 5); // =AVERAGE(3,7)
		assert(object.MeanY() == 5); // =AVERAGE(3,7)
		assert(object.Var() == 8); // =COVARIANCE.S({3,7},{3,7})
		object.Add(11, 11);
		assert(object.MeanX() == 7); // =AVERAGE(3,7,11)
		assert(object.MeanY() == 7); // =AVERAGE(3,7,11)
		assert(object.Var() == 16); // =COVARIANCE.S({3,7,11},{3,7,11})
	}
	{
		Covariance object;
		object.Add(3, 11);
		assert(object.MeanX() == 3); // =AVERAGE(3)
		assert(object.MeanY() == 11); // =AVERAGE(3)
		assert(object.Var() == 0); // =COVARIANCE.S({3},{11})
		object.Add(7, 7);
		assert(object.MeanX() == 5); // =AVERAGE(3,7)
		assert(object.MeanY() == 9); // =AVERAGE(11,7)
		assert(object.Var() == -8); // =COVARIANCE.S({3,7},{11,7})
		object.Add(11, 3);
		assert(object.MeanX() == 7); // =AVERAGE(3,7,11)
		assert(object.MeanY() == 7); // =AVERAGE(11,7,3)
		assert(object.Var() == -16); // =COVARIANCE.S({3,7,11},{11,7,3})
	}
	std::cout << "ok";
	std::cin.get();
}