Background
==========

This implementation is the one on Wikipedia [here](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#Online)  

The corresponding mathematical formula is  
![Image description](https://wikimedia.org/api/rest_v1/media/math/render/svg/f440f49beea73d0aeec36d0101caa20f89e864aa)

```
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
		return (count > 0) ? meanx : 0.0;
	}
	double MeanY() const {
		return (count > 0) ? meany : 0.0;
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
```

