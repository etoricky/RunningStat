#include <iostream>
#include <assert.h>

class Covariance {
public:
	void Add(double x) {
		Add(x, x);
	}
	void Add(double x, double y) {
		count++;
		const double last_meanx = meanx, last_meany = meany;
		meanx = meanx + (x - meanx) / count;
		meany = meany + (y - meany) / count;
		sumx = sumx + (x - last_meanx) * (x - meanx);
		sumy = sumy + (y - last_meany) * (y - meany);
		sum = sum + (x - last_meanx) * (y - meany);
	}
	int Count() const {
		return count;
	}
	double MeanX() const {
		return meanx;
	}
	double MeanY() const {
		return meany;
	}
	double VarX() const {
		return ((count > 1) ? sumx / (count - 1) : 0.0);
	}
	double VarY() const {
		return ((count > 1) ? sumy / (count - 1) : 0.0);
	}
	double Cov() const {
		return ((count > 1) ? sum / (count - 1) : 0.0);
	}
	double Std() const {
		return sqrt(Cov());
	}
private:
	int count = 0;
	double meanx = 0, meany = 0, sum = 0, sumx = 0, sumy = 0;
};

void main() {
	{
		Covariance object;
		object.Add(3);
		assert(object.MeanX() == 3); // =AVERAGE(3)
		assert(object.MeanY() == 3); // =AVERAGE(3)
		assert(object.VarX() == 0); // =VAR.S(3)
		assert(object.VarY() == 0); // =VAR.S(3)
		assert(object.Cov() == 0); // =COVARIANCE.S({3},{3})
		object.Add(7);
		assert(object.MeanX() == 5); // =AVERAGE(3,7)
		assert(object.MeanY() == 5); // =AVERAGE(3,7)
		assert(object.VarX() == 8); // =VAR.S(3,7)
		assert(object.VarY() == 8); // =VAR.S(3,7)
		assert(object.Cov() == 8); // =COVARIANCE.S({3,7},{3,7})
		object.Add(11);
		assert(object.MeanX() == 7); // =AVERAGE(3,7,11)
		assert(object.MeanY() == 7); // =AVERAGE(3,7,11)
		assert(object.VarX() == 16); // =VAR.S(3,7,11)
		assert(object.VarY() == 16); // =VAR.S(3,7,11)
		assert(object.Cov() == 16); // =COVARIANCE.S({3,7,11},{3,7,11})
	}
	{
		Covariance object;
		object.Add(3, 11);
		assert(object.MeanX() == 3); // =AVERAGE(3)
		assert(object.MeanY() == 11); // =AVERAGE(3)
		assert(object.VarX() == 0); // =VAR.S(3)
		assert(object.VarY() == 0); // =VAR.S(11)
		assert(object.Cov() == 0); // =COVARIANCE.S({3},{11})
		object.Add(7, 7);
		assert(object.MeanX() == 5); // =AVERAGE(3,7)
		assert(object.MeanY() == 9); // =AVERAGE(11,7)
		assert(object.VarX() == 8); // =VAR.S(3,7)
		assert(object.VarY() == 8); // =VAR.S(11,7)
		assert(object.Cov() == -8); // =COVARIANCE.S({3,7},{11,7})
		object.Add(11, 3);
		assert(object.MeanX() == 7); // =AVERAGE(3,7,11)
		assert(object.MeanY() == 7); // =AVERAGE(11,7,3)
		assert(object.VarX() == 16); // =VAR.S(3,7,11)
		assert(object.VarY() == 16); // =VAR.S(11,7,3)
		assert(object.Cov() == -16); // =COVARIANCE.S({3,7,11},{11,7,3})
	}
	std::cout << "ok";
	std::cin.get();
}